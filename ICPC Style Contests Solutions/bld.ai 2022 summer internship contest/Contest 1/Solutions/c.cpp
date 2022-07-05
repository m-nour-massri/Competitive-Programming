
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e5+9,MX=1e12+9;
int n,m;
bool vis[inf];
vector<vector<pair<int,int> > > adj,rev_adj;
vector<int> dis;
pair<int,int> ans = make_pair(MX,0);

struct Home{
    int u;
    vector<int> dis,rev_dis;
}homes[6];


vector<int> dij(int x,vector<vector<pair<int,int> >> &v){

    for(int i=1;i<=n;i++)
        dis[i]=MX,vis[i] = 0;

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
                dis[o.first]=dis[node]+o.second,
                s.insert(make_pair(dis[o.first],o.first));
    }

    return dis;
}

void calc(Home &x,Home &y,Home &z){
    for(int i=1;i<=n;i++)
        ans = min(ans,make_pair(x.rev_dis[i] + y.dis[i] + z.dis[i],x.u));

}

signed main(){
    ios::sync_with_stdio(0);

    cin>>n>>m;
    dis.resize(n+3);
    adj.resize(n+3);
    rev_adj.resize(n+3);
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        rev_adj[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=3;i++){
        cin>>homes[i].u;
        homes[i].dis = dij(homes[i].u,adj);
        homes[i].rev_dis = dij(homes[i].u,rev_adj);
    }
    calc(homes[1],homes[2],homes[3]);
    calc(homes[2],homes[1],homes[3]);
    calc(homes[3],homes[1],homes[2]);

    if(ans.first >= MX)
        cout<<-1<<endl;
    else
        cout<<ans.second<<" "<<ans.first<<endl;
}
