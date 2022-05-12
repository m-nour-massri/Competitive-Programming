
//USACO 2014 December Contest, Silver
//Problem 1. Piggyback
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=4e4+9,MX=1e9+9;
ll n,m,x,y,z,ans=MX;
vector<ll> v[inf];

vector<ll> bfs(ll start){

    vector<ll> dis(n+2,MX),vis(n+2,0);
    dis[start]=0;
    queue<ll>q;
    q.push(start);
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        if(vis[node])
            continue;
        vis[node]=1;
        for(auto o:v[node])
            if(dis[o]>dis[node]+1)
                dis[o]=dis[node]+1,q.push(o);
    }
    return dis;
}
int main(){

    freopen("piggyback.in","r",stdin);
    freopen("piggyback.out","w",stdout);
    cin>>x>>y>>z>>n>>m;
    for(ll i=1;i<=m;i++){
        ll a,b;
        cin>>a>>b;
        v[b].push_back(a);
        v[a].push_back(b);
    }

    vector<ll> dis1=bfs(1),dis2=bfs(2),disn=bfs(n);

    for(ll i=1;i<=n;i++)
        ans=min(ans,dis1[i]*x+dis2[i]*y+disn[i]*(min(x+y,z))  );

    cout<<ans<<endl;
}