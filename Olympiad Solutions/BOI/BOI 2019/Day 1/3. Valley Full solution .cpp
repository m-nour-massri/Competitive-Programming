//BOI 2019 Day 1 Problem 3 Valley
//Full solution
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e5+9,lg=18,MX=2e18+9;
ll n,s,q,E,temp;
bool shop[inf];
ll par[inf][lg],mn[inf][lg],level[inf],NearestShop[inf],dis[inf],x[inf],y[inf],z[inf];
vector<pair<ll,ll> > adj[inf];
//NearestShop[i] = distance to nearest shop in the subtree of i - 2*dis[i]
//mn[i][j] = minimum of NearestShop [x] where x is on the path between i and 2^j th parent of i

void dfs(ll u,ll p){

    par[u][0]=p;
    level[u]=level[p]+1;
    NearestShop[u]=(shop[u]?dis[u]:MX);

    for(auto v:adj[u])
        if(v.first!=p)
            dis[v.first]=dis[u]+v.second,dfs(v.first,u),NearestShop[u]=min(NearestShop[u],NearestShop[v.first]);
}

void preprocess(){

    dfs(E,0);

    for(ll i=1;i<=n;i++)
        NearestShop[i]+=-2*dis[i];

    for(int i=1;i<=n;i++)
        mn[i][0]=NearestShop[par[i][0]];

    for(ll j=1;j<lg;j++)
        for(ll i=1;i<=n;i++)
            par[i][j]=par[par[i][j-1]][j-1],
            mn[i][j]=min(mn[i][j-1],mn[par[i][j-1]][j-1]);
}

pair<ll,ll> LCA(ll x,ll y){

    if(level[x]>level[y])
        swap(x,y);
    ll diff=level[y]-level[x],ret=NearestShop[y];

    for(ll i=lg-1;i>=0;i--)
        if(diff&(1<<i))
            ret=min(ret,mn[y][i]),y=par[y][i];

    if(x==y)
        return make_pair(x,ret);

    return make_pair(0,MX);
}

int main(){

    cin>>n>>s>>q>>E;
    for(ll i=1;i<n;i++)
        cin>>x[i]>>y[i]>>z[i],
        adj[x[i]].push_back(make_pair(y[i],z[i])),
        adj[y[i]].push_back(make_pair(x[i],z[i]));

    for(ll i=1;i<=s;i++)
        cin>>temp,shop[temp]=1;

    preprocess();

    while(q--){
        ll idx,R,lower_node;
        cin>>idx>>R;
        if(level[x[idx]]<level[y[idx]] )//lower node of the edge have larger level
            lower_node=y[idx];
        else
            lower_node=x[idx];

        pair<ll,ll> lca_min=LCA(lower_node,R);
        if(lca_min.first!=lower_node)//R is not in the subtree of lower_node so it can escape to the root E
                cout<<"escaped"<<endl;
        else
            if(lca_min.second>=MX/4)
                cout<<"oo"<<endl;
            else
                cout<<lca_min.second+dis[R]<<endl;
    }
}