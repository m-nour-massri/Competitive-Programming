
//COCI 15-galaksija

we create an prefix Xor array where PreXor[i] is the Xor of all values of the edges from the root to node i 
if two nodes have the same PreXor value then the road between them is boring 
we create a map for sotring Prefix Xor in each subgraph 
after each destruction one subgraph is divided into two subgraphs we choose the smallest one and create a 
new map and remove the PreXor values of its nodes to the new map and recalculate the answer 
by moving small to larger it runs in O(n*logn) and Logn factor of the map

it sums up to O ( N*log(n)^2 ) 

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long  inf = 1e5+9;

bool DeletedEdge[inf];
ll SubgraphCount = 1;
ll  n,Subgraph[inf],sz[inf],level[inf],PreXor[inf],ans,root[inf],Cnt[inf];
ll  x[inf],y[inf],z[inf];
vector<pair<ll ,pair<ll ,ll > > > adj[inf];
map<ll ,ll > mp[inf];


void Modify(ll  Root,ll  Val,ll  Add){

    Cnt [ Root] += Add;
    ll  cur = mp[Root][Val];

    ans -= cur*(cur-1)/2;

    mp[Root][Val] += Add;
    cur += Add;
    ans += cur*(cur-1)/2;

}

void dfs1(ll  u,ll  par){

    root[u] = 1;
    sz[u] = 1;
    Subgraph[u] = SubgraphCount;
    Modify(Subgraph[u], PreXor[u],1 );

    for(auto p:adj[u]){
        ll  v= p.first,w = p.second.first;
        if(v == par)
            continue;
        PreXor[v] = PreXor[u] ^ w;
        level[v] = level[u] + 1;
        dfs1(v,u);
        sz[u] += sz[v];
    }
}

void dfs2(ll  u,ll  par,ll  OldSubgraph){


    Subgraph[u] = SubgraphCount;
    Modify(OldSubgraph,PreXor[u],-1);
    Modify(SubgraphCount,PreXor[u],+1);

    for(auto p:adj[u]){
        ll  v = p.first,idx = p.second.second;
        if(v != par && !DeletedEdge[idx])
            dfs2(v,u,OldSubgraph);
    }
}

int  main(){


    scanf("%lld",&n);
    for(ll  i=1;i<n;i++){
        scanf("%lld%lld%lld",x+i,y+i,z+i);

        adj[ x[i] ].push_back( make_pair(y[i],make_pair(z[i],i) ) );
        adj[ y[i] ].push_back(make_pair( x[i],make_pair(z[i],i) ) );
    }
    dfs1(1,0);
    printf("%lld\n",ans);

    for(ll  i=1;i<n;i++){
        ll  Del;
        scanf("%lld",&Del);
        DeletedEdge[Del] = 1;

        ll  u = x[Del],v = y[Del];
        if( level[u] > level[v] )
            swap(u,v);

        SubgraphCount++;
        if(Cnt[ Subgraph[u] ] - sz[v] < sz[v])
            dfs2(u,0,Subgraph[u]);
        else
            dfs2(v,0,Subgraph[u]);

       printf("%lld\n",ans);
    }
}
