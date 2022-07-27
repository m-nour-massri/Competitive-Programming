#include<bits/stdc++.h>
#define int long long
#define other(x) (x<=m?x+m:x-m)
using namespace std;
const int inf = 2e5+9;
vector<int>adj[inf];
int n,m;
int timer, SCC_cnt;
int num[inf],low[inf],cmp[inf],ans[inf];

bool inStack[inf];
stack<int> s;

void dfs(int u){

    num[u] = low[u] = ++timer;
    s.push(u);
    inStack[u] = 1;

    for(auto v:adj[u]){
        if ( num[v] == -1){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
            low[u] = min(low[u], num[v]);
    }

    if ( num[u] == low[u]){
        SCC_cnt++;
        int v;
        do{
            v = s.top();  s.pop();
            inStack[v] = 0;
            cmp[v] = SCC_cnt;
            if(ans[(v>m?v-m:v)] == -1)
                ans[(v>m?v-m:v)] = (v>m?0:1);
        }
        while (u != v);
    }
}

signed main()
{
    memset(num,-1,sizeof num);
    memset(low,-1,sizeof low);
    memset(ans,-1,sizeof ans);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u,v,x,y;
        cin>>u>>v;
        x = abs(u) + m*(u < 0);
        y = abs(v) + m*(v < 0);
        adj[other(x)].push_back(y);
        adj[other(y)].push_back(x);
    }

    for(int i=1;i<=m+m; i++)
        if(num[i] == -1)
                dfs(i);
    for(int i=1;i<=m;i++)
        if(cmp[i] == cmp[i+m])
            cout<<-1,exit(0);
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
}