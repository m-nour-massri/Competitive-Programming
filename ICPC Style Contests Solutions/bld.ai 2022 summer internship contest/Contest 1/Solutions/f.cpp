

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf =1e5+9;
int n,in[inf],dp[inf],ans = 1;
string a[inf];
map<string,int> mp;
vector<int> adj[inf];

string get(string x,int j){
    return x.substr(0,j) + x.substr(j+1,n-j-1);
}

void dfs(int u){
    dp[u] = 1;
    for(auto v:adj[u])
        if(dp[v] == -1)
            dfs(v),dp[u] = max(dp[u],dp[v] + 1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]] = i,dp[i] = -1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)a[i].size();j++){
            string tmp = get(a[i],j);
            if(mp[tmp])
                adj[ mp[tmp] ].push_back(i),in[i]++;
        }
    }

  for(int i=1;i<=n;i++)
    if(in[i] == 0)
        dfs(i),ans = max(ans,dp[i]);

    cout<<ans<<endl;
}

