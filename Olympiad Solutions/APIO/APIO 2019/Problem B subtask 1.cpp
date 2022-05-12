//Problem B subtask 1
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const int inf=1e3+9;
int n,m,q,x[inf],y[inf],z[inf];
multiset<pair<int,int> > adj[inf];
bool vis[inf];

int dfs(int node,int weight){
    int ret=1;
    vis[node]=1;
    for(auto o:adj[node])
        if(!vis[o.first] && weight<=o.second)
            ret+=dfs(o.first,weight);
    return ret;
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=m;i++){

        cin>>x[i]>>y[i]>>z[i];
        adj[x[i]].insert(make_pair(y[i],z[i]));
        adj[y[i]].insert(make_pair(x[i],z[i]));
    }

    cin>>q;
    while(q--){

        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            adj[x[a]].erase(adj[x[a]].find(make_pair(y[a],z[a])) ),adj[y[a]].erase(adj[y[a]].find(make_pair(x[a],z[a]))),z[a]=b;
            adj[x[a]].insert(make_pair(y[a],z[a])),adj[y[a]].insert(make_pair(x[a],z[a]));
        }
        else {
            memset(vis,0,sizeof(vis));
            cout<<dfs(a,b)<<endl;
        }
    }
}
