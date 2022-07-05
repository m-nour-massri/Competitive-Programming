//USACO 2018 US Open Contest, Bronze
//Problem 3. Family Tree
#include <bits/stdc++.h>
using namespace std;
const int inf=209,lg=11;
int n,cnt;
vector<int> adj[inf];
int parent[inf][lg],level[inf];
map<string,int> mp;
string x,y,a[inf],b[inf];

void dfs(int u,int par ){
    for(auto v:adj[u])
        if(v!=par)
            level[v] = level[u] +1,dfs(v,u);
}

int LCA(int u,int v){

    if(level[u] > level[v])
        swap(u,v);
    int diff=level[v]-level[u];
    for(int j=lg-1;j>=0;j--)
        if(diff & (1<<j))
            v = parent[v][j];
    if(v == u)
        return v;
    for(int j=lg-1;j>=0;j--)
        if( parent[u][j] != parent[v][j] )
            u = parent[u][j] , v = parent[v][j];
    return (u == v ? u : parent[v][0]);
}

int main(){

    freopen("family.in","r",stdin);
    freopen("family.out","w",stdout);

    cin>>n>>x>>y;
    mp[x],mp[y];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp[a[i]],mp[b[i]];
    }

    for(auto &o:mp)
        o.second = ++cnt;
    for(int i=1;i<=n;i++)
        adj[mp[a[i]]].push_back(mp[b[i]]),
        adj[mp[b[i]]].push_back(mp[a[i]]),
        parent[mp[b[i]]][0] = mp[a[i]];

    for(int i=1;i<=cnt;i++)
        if(parent[i][0] == 0)
            dfs(i,0);
    for(int j=1;j<lg;j++)
        for(int i=1;i<=cnt;i++)
            parent[i][j] = parent[parent[i][j-1]][j-1];

    int u=mp[x],v=mp[y];
    int lca = LCA(u,v);
    if( lca == 0 )
        cout<<"NOT RELATED"<<endl,exit(0);

    if(lca == u){
        cout<<x<<" is the ";
        int diff = level[v] - level[u]-1;
        for(int i=1;i<diff;i++)
            cout<<"great-";
        if(diff >= 1)
            cout<<"grand-";
        cout<<"mother of "<<y<<endl;
        exit(0);
    }
    else if(lca == v){
         cout<<y<<" is the ";
        int diff = level[u] - level[v]-1;
        for(int i=1;i<diff;i++)
            cout<<"great-";
        if(diff >= 1)
            cout<<"grand-";
        cout<<"mother of "<<x<<endl;
        exit(0);
    }
    bool isx=0,isy=0;
    for(auto o:adj[lca])
        if(o == u)
            isx=1;
        else if(o == v)
            isy=1;
    if(isx && isy)
        cout<<"SIBLINGS"<<endl;
    else if(isx){
        cout<<x<<" is the ";
        int diff = level[v] - level[u]-1;
        while(diff-->0)
            cout<<"great-";
        cout<<"aunt of "<<y<<endl;
    }
    else if( isy ){
        cout<<y<<" is the ";
        int diff = level[u] - level[v]-1;
        while(diff-->0)
            cout<<"great-";
        cout<<"aunt of "<<x<<endl;
    }
    else
        cout<<"COUSINS"<<endl;
}