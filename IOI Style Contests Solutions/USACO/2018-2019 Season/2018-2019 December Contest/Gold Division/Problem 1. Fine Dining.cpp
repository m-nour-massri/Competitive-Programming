//USACO 2018 December Contest, Gold
//Problem 1. Fine Dining
#include <bits/stdc++.h>
using namespace std;
const int inf=5e4+9,MX=1e9+9;
vector<pair<int,int> > v[inf];
vector<int> dis1,dis2;
int n,m,k;
pair<int,int> hay[inf];

vector<int> dij(int x){

    vector<int> dis(n+3);
    bool vis[inf]={0};
    for(int i=1;i<x;i++)
        dis[i]=MX;

    dis[x]=0;
    set<pair<int,int> > s;
    s.insert(make_pair(0,x));

    while(!s.empty()){

        pair<int,int> p=*s.begin();
        s.erase(s.begin());
        int node=p.second;
        if(vis[node])
            continue;
        vis[node]=1;
        for(auto o:v[node])
            if(dis[o.first]>dis[node]+o.second)
                dis[o.first]=dis[node]+o.second,s.insert(make_pair(dis[o.first],o.first));
    }

    return dis;
}


int main(){

    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=k;i++)
        cin>>hay[i].first>>hay[i].second;

    dis1=dij(n);

    for(int i=1;i<=k;i++)
        v[n+1].push_back(make_pair(hay[i].first,dis1[hay[i].first]-hay[i].second));

    dis2=dij(n+1);

    for(int i=1;i<n;i++)
        if(dis1[i]>=dis2[i])
            cout<<1<<endl;
        else cout<<0<<endl;
}