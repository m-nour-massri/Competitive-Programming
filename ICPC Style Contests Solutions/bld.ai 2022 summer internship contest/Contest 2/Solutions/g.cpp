#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9,MX=1e9+9;
int n,m,q,x[inf],y[inf];
struct Edge{
    int u,v,w;
    bool operator <(Edge other){
        return w > other.w;
    }
}edges[inf];

int sz[inf],par[inf],ans[inf];
set<int> S[inf];


int root(int x){
    return (x==par[x]?x:par[x]=root(par[x]));
}

void uni(int x,int y,int id){

    x=root(x);
    y=root(y);
    if(x == y)return ;

    if (S[x].size() > S[y].size() || (S[x].size() == S[y].size() && sz[x] > sz[y]))
        swap(x, y);

    for(auto o:S[x]){
        if(S[y].find(o)!=S[y].end())
            ans[o]=id,S[y].erase(o);
        else
            S[y].insert(o);
    }
    par[x]=y;
    sz[y]+=sz[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        sz[i]=1,par[i]=i;

    for(int i=1;i<=m;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;

    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        S[x].insert(i),S[y].insert(i);
    }
    sort(edges+1,edges+1+m);
    for(int i=1;i<=m;i++){
        uni(edges[i].u,edges[i].v,edges[i].w);
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
}