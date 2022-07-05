//USACO 2012 December Contest, Gold
//Problem 3. Running Away From the Barn
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=2e5+9,lg=20;
ll n,k;
vector<pair<ll,ll> > adj[inf];
ll depth[inf],sparse[inf][lg],ans[inf];

void dfs(ll u,ll par){

    sparse[u][0]=par;
    for(auto v:adj[u])
        if(v.first != par)
            depth[v.first]=depth[u]+v.second,dfs(v.first,u);
}

void DfsCalc(ll u,ll par){

    for(auto v:adj[u])
        if(v.first != par)
            DfsCalc(v.first,u),ans[u]+=ans[v.first];
}

int main(){

    freopen("runaway.in","r",stdin);
    freopen("runaway.out","w",stdout);

    cin>>n>>k;
    for(ll i=2;i<=n;i++){
        ll par,cost;
        cin>>par>>cost;
        adj[par].push_back(make_pair(i,cost));
        adj[i].push_back(make_pair(par,cost));
    }
    dfs(1,0);
    for(ll j=1;j<lg;j++)
        for(ll i=1;i<=n;i++)
            sparse[i][j] = sparse[ sparse[i][j-1] ][j-1];

    for(ll i=1;i<=n;i++){
        ll v=i;
        for(ll j=lg-1;j>=0;j--)
            if(  depth[i] - depth[ sparse[v][j] ]  <=k )
                v = sparse[v][j];
         ans[ sparse[v][0] ]--;
         ans[i]++;
    }
    DfsCalc(1,0);
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<"\n";
}