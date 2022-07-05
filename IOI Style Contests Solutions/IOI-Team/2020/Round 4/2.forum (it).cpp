
//IOI team 2.Forum Management (forum)
#include <bits/stdc++.h>
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const int inf = 1e6+9;
int n,m,q,tree[inf<<2],id[inf],in[inf],out[inf],timer = 1,lazy[inf<<2];
vector<int> v[inf];

void dfs(int node,int par){

    in[node] = timer++;
    id[timer-1] = node;
    for(auto o:v[node])
        if( o != par )
            dfs(o,node);
    out[node] =timer-1;
}
void push(int node,int l,int r){
    if(lazy[node] == - 1)
        return ;
    if(l != r)
        lazy[le] = lazy[ri] = lazy[node];
    tree[node] = lazy[node] ;
    lazy[node] = -1;
}

void update(int node,int l,int r,int x,int y,int val){
    push(node,l,r);
    if(l>r || r<x || l>y)
        return ;
    if(l>=x && r<=y){
        lazy[node] = val;
        push(node,l,r);
        return ;
    }
    update(le,l,mid,x,y,val);
    update(ri,mid+1,r,x,y,val);
}

int query(int node,int l,int r,int idx){
    push(node,l,r);
    if(l == r)
        return tree[node];
    if(idx <= mid)
        return query(le,l,mid,idx);
    return query(ri,mid+1,r,idx);
}

int main(){
    memset(lazy,-1,sizeof(lazy));
    scanf("%d%d%d",&n,&m,&q);
    n += m;
    for(int i=1;i<=n;i++){
        int par;
        scanf("%d",&par);
        if(par == -1)
            continue;
        par++;
        v[par].push_back(i);
        v[i].push_back(par);
    }

    dfs(1,0);
    while(q--){
        int type , cur;
        scanf("%d%d",&type,&cur);
        cur++;
        if(type == 0)
            update(1,1,n,in[cur],out[cur],0);
        else if(type == 1)
            update(1,1,n,in[cur],out[cur],1);
        else
            printf("%d\n",query(1,1,n,in[cur]));
    }
}
