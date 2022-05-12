//USACO 2012 December Contest, Silver
//Problem 3. Milk Routing
#include <bits/stdc++.h>
using namespace std;
const int inf=509,MX=1e9+9;

int n,m,k,ans=MX;
set<pair<int,int> > s;
vector<pair<int,int> > adj[inf];
int cost[inf],capacity[inf],dis[inf],vis[inf];

int go(int x){

    s.clear();
    memset(dis,21,sizeof(dis));
    memset(vis,0,sizeof(vis));

    s.insert(make_pair(0,1));
    dis[1]=0;
    while(!s.empty()){
        int u=(*s.begin()).second;
        s.erase(s.begin());
        if(vis[u])
            continue;
        vis[u]=1;
        if( u == n)
            return dis[u];

        for(auto o:adj[u]){
            int v=o.first,c=cost[o.second],d=capacity[o.second];
            if(d<x)
                continue;
            if( dis[v] > dis[u]+c )
                dis[v] = dis[u]+c,s.insert(make_pair(dis[v],v));
        }
    }
    return MX;
}

int main(){

    freopen("mroute.in","r",stdin);
    freopen("mroute.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b>>cost[i]>>capacity[i];
        adj[a].push_back(make_pair(b,i));
        adj[b].push_back(make_pair(a,i));
    }

    for(int i=1;i<=m;i++)
        ans=min(ans, go(capacity[i]) + k/capacity[i]  );

    cout<<ans<<endl;
}