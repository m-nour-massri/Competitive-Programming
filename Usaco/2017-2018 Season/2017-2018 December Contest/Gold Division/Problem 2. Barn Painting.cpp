//USACO 2017 December Contest, Gold
//Problem 2. Barn Painting
//dp on tree problem
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e5+9,mod=1e9+7;
ll dp[inf][5];
vector<ll> v[inf];

void dfs(ll node,ll par){

    for(auto o:v[node]){
        if(o==par)
            continue;

        dfs(o,node);

        dp[node][0]*=(dp[o][1]+dp[o][2])%mod;
        dp[node][0]%=mod;

        dp[node][1]*=(dp[o][0]+dp[o][2])%mod;
        dp[node][1]%=mod;

        dp[node][2]*=(dp[o][0]+dp[o][1])%mod;
        dp[node][2]%=mod;
    }
}

int main(){
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);
    ll n,k;
    cin>>n>>k;

    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        dp[i][0]=dp[i][1]=dp[i][2]=1;
    }
    dp[n][0]=dp[n][1]=dp[n][2]=1;

    while(k--){
        ll x,color;
        cin>>x>>color;
        color--;
        dp[x][0]=dp[x][1]=dp[x][2]=0;
        dp[x][color]=1;
    }

    dfs(1,-1);
    cout<<(dp[1][0]+dp[1][1]+dp[1][2])%mod<<endl;
}