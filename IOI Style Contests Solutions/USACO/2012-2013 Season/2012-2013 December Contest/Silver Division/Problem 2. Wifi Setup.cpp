//USACO 2012 December Contest, Silver
//Problem 2. Wifi Setup
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=2e3+9,MX=1e18+9;
ll n, a,b,arr[inf],dp[inf],vis[inf];

ll solve(ll pos){

    if(pos==n+1)
        return 0;

    ll &ret=dp[pos];
    if(vis[pos])
        return ret;
    vis[pos]=1;
    ret=MX;
    for(ll i=pos;i<=n;i++){
        ll dis=arr[i]-arr[pos];
        ret=min(ret,solve(i+1)+a+a+b*dis);
    }
    return ret;
}

int main(){
    freopen("wifi.in","r",stdin);
    freopen("wifi.out","w",stdout);

    cin>>n>>a>>b;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];

    sort(arr+1,arr+1+n);
    ll ans=solve(1);
    cout<<ans/2ll<<(ans%2?".5\n":"\n");
}