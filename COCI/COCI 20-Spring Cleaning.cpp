
/*
my solution is mention the editorial (HLD approach)
https://codeforces.com/blog/entry/82022

but here is a brief explanation written by me:

observation:
for each node u if it has x leafs inside its subtree then we will only take
    (1 if x is odd or 2 if x is even ) to pair them with nodes outside the
    subtree of node u and other nodes will be paired with each other
    then the 1 or 2 nodes will cost us edge upwards

    so for every node except the root (root from a node that is not a leaf)
    if number of leafs inside its subtree is even we add 2 to the answer
    if it is odd we add 1 to the answer
    then we add the number of final leafs to the answer

    anyway the tree is changed every subtree so adding leafs to node u
    changes the number of leafs of all the ancestors of u and changes the final
    answer so we need to update the state (even or odd ) for each node
    from u to the root so we use hld

    and we should be aware that some nodes are no longer leafs
    then we calculate the answer after the update as mentioned above
    then we remove the updates by updating again to return to the original tree

    we pay attention to the state that number of leafs is odd then
    the answer is -1
*/

#include <bits/stdc++.h>
#define ll long long
#define le node+node
#define ri node+node+1
#define mid (l+r)/2
using namespace std;
const ll inf = 1e5+9;
ll n,q,Root,OriginalLeaves;
ll Leaves[inf],CntAdd[inf];
vector<ll> adj[inf],tmp;

ll tree[inf<<2][2],lazy[inf<<2];

ll parent[inf],heavy[inf],depth[inf],root[inf],SegTreePos[inf],id[inf];

    void merge(int node,int l,int r){
        tree[node][0] = tree[le][0] + tree[ri][0];
        tree[node][1] = tree[le][1] + tree[ri][1];
    }
    void PushLazy(int node,int l,int r){

        if( (lazy[node] % 2) == 0)
            return void(lazy[node] = 0);
        swap(tree[node][0],tree[node][1]);
        if(l != r)
            lazy[le] += lazy[node],lazy[ri] += lazy[node];
        lazy[node] = 0;
    }
    void build(int node,int l,int r){
        if(l == r)
            return void(tree[node][Leaves[id[l]]%2]++);
        build(le,l,mid);
        build(ri,mid+1,r);
        merge(node,l,r);
    }

    void update(int node,int l,int r,int x,int y,int val){
        PushLazy(node,l,r);
        if(l>r || r<x || l>y)
            return ;
        if(l>=x && r<=y){
            lazy[node] = val;
            PushLazy(node,l,r);
            return ;
        }
        update(le,l,mid,x,y,val);
        update(ri,mid+1,r,x,y,val);
        merge(node,l,r);
    }

    ll query(ll node,ll l,ll r,ll idx){
        PushLazy(node,l,r);
        if(l>r || l>idx || r<idx)
            return -1000;
        if(l == r)
            return tree[node][0]?2:1;

        ll ret= max(query(le,l,mid,idx), query(ri,mid+1,r,idx));
        merge(node,l,r);
        return ret;
    }

    ll dfs_hld(ll u){
        ll size=1,MaxSubtree=0;

        for(auto v:adj[u]){
            if(v == parent[u])
                continue;
            parent[v]=u;
            depth[v]=depth[u]+1;

            ll ChildTreeSize=dfs_hld(v);
            Leaves[u]+= Leaves[v] + (Leaves[v] == 0);

            if(ChildTreeSize>MaxSubtree)
                MaxSubtree=ChildTreeSize,heavy[u]=v;
            size+=ChildTreeSize;
        }

        return size;
    }

    void BuildChains(){

        memset(heavy,-1, sizeof(heavy) );
        dfs_hld(Root);
        for(ll ChainRoot=1 , pos=0 ; ChainRoot<=n ; ChainRoot++)
            if( heavy[  parent[  ChainRoot  ] ] != ChainRoot )
                for( ll j=ChainRoot ; j!=-1  ; j= heavy[ j ] )
                    root[j]=ChainRoot,SegTreePos[j]=++pos,id[pos] = j;

        build(1,1,n);
    }

    void update(ll u,ll v,ll val){
        if( min(u,v) == 0 )
            return ;
        for(;  root[u] != root[v]  ;  v=parent[ root[v] ]  ){
            if( depth[ root[u] ] > depth[ root[v] ] )
                swap(u,v);
            update(1,1,n, SegTreePos[ root[ v ] ] , SegTreePos[ v ] , val);
        }
        if( depth[u] > depth[v] )
            swap(u,v);
        update(1,1,n, SegTreePos[ u ] , SegTreePos[ v ] , val);
    }

int main(){

    scanf("%I64d%I64d",&n,&q);
    for(ll i=1;i<n;i++){
        ll u,v;
        scanf("%I64d%I64d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=n;i>=1;i--)
        if(adj[i].size() > 1)
            Root = i;
    BuildChains();
    OriginalLeaves = Leaves[Root];

    while(q--){
        ll d,LeafParent;
        scanf("%I64d",&d);

        ll CurrentLeaves = d,CurrentOriginalLeaves = OriginalLeaves;

        while(d--){
            scanf("%I64d",&LeafParent);
            CntAdd[LeafParent]++;
            if(CntAdd[LeafParent] == 1)
                tmp.push_back(LeafParent);
            if(adj[LeafParent].size() == 1 && CntAdd[LeafParent] == 1)
                CurrentOriginalLeaves--;
        }
        CurrentLeaves += CurrentOriginalLeaves;

        for(auto u:tmp)
            if(adj[u].size() == 1)
                update(u,u,CntAdd[u]),update(Root,parent[u],CntAdd[u]-1);
            else
                update(Root,u,CntAdd[u]);

        if(CurrentLeaves % 2)
            puts("-1");
        else
            printf("%I64d\n",tree[1][0]*2ll +
                   tree[1][1] + CurrentLeaves -
                   CurrentOriginalLeaves*2ll -
                   query(1,1,n,SegTreePos[Root]));

        for(auto u:tmp){
            if(adj[u].size() == 1)
                update(u,u,CntAdd[u]),update(Root,parent[u],CntAdd[u]-1);
            else
                update(Root,u,CntAdd[u]);
            CntAdd[u] = 0;
        }
        tmp.clear();
    }
}


