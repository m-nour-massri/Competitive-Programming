//IOI Team 7.Ropes Escape (ropes)


#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 1e5+9;
ll a[inf],b[inf],n,dp[inf];
vector<pair<ll,ll> > v[inf];

void dfs(ll node,ll par){

    ll mx = 0;
    for(auto o:v[node]){
        if(o.first == par)
            continue;
        dfs(o.first,node);
        mx = max(mx,o.second);
        dp[node] += dp[o.first] + o.second;
    }
    dp[node] -= mx;

}

int main(){
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
        cin>>b[i];
    for(ll i=1;i<=n;i++){
        v[ a[i] ].push_back(make_pair(i,b[i]));
        v[ i ].push_back(make_pair(a[i],i));
    }
    dfs(0,0);
    cout<<dp[0]<<endl;
}