
//USACO 2016 December Contest, Gold
//Problem 3. Lasers and Mirrors
#include <bits/stdc++.h>
using namespace std;
const int inf=2e5+9,MX=1e9+9;
int n,cnt,x[inf],y[inf],dis[inf][2],vis[inf][2];
map<int,vector<int> > AdjX,AdjY;
map<int,int> mp;
queue<pair<int,int> > q;

int main(){

    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    cin>>n>>x[0]>>y[0];
    cin>>x[n+1]>>y[n+1];
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i],
        AdjX[ x[i] ].push_back(i),
        AdjY[ y[i] ].push_back(i),
        dis[i][0] = dis[i][1] = MX;

    AdjX[ y[n+1] ].push_back(n+1);
    AdjY[ x[n+1] ].push_back(n+1);
    dis[n+1][0] = dis[n+1][1] = MX;
    q.push( make_pair(0,1) );//1 denotes y
    q.push( make_pair(0,0) );//0 denotes x
    dis[0][0] = dis[0][1] = 0;

        while(!q.empty()){
        int idx=q.front().first,isy=q.front().second;
        q.pop();
        if( vis[idx][isy] )
            continue;
        vis[idx][isy] = 1;
        if(isy && y[idx] == y[n+1])
            cout<<dis[idx][isy]<<endl,exit(0);
        if(!isy && x[idx] == x[n+1])
            cout<<dis[idx][isy]<<endl,exit(0);
        if(isy){
            for(auto o:AdjY[ y[idx] ])
                if( dis[o][0] > dis[idx][1] +1 )
                    dis[o][0] = dis[idx][1] +1,q.push(make_pair(o,0));
        }
        else{
            for(auto o:AdjX[ x[idx] ])
                if(dis[o][1] > dis[idx][0] +1)
                    dis[o][1] = dis[idx][0] +1,q.push(make_pair(o,1));
        }
    }
    puts("-1");

}
