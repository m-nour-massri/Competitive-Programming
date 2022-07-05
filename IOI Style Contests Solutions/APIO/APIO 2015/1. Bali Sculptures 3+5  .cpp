//APIO 2015 Bali Sculptures
//3,5 subtasks solution 50 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e3+9,MX=1e9+9;
ll n,x,y,a[N],pre[N],dp[N];
ll ans ;

ll solve(ll pos){

    if( pos == n+1)
        return  0;

    ll &ret=dp[pos];
    if(ret != -1)
        return ret;
    ret = MX;
    for(ll i=pos;i<=n;i++)
        if( ( (pre[i]-pre[pos-1]) | ans ) == ans )// we don't want set-bits that are not set in ans
            ret = min(ret,1+solve(i+1) ) ;
    return ret;
}

int main(){

    cin>>n>>x>>y;
    for(ll i=1;i<=n;i++)
        cin>>a[i],pre[i]=a[i]+pre[i-1];

    ans = (1ll<<61)-1;
    for(ll i=60;i>=0;i--){
        memset(dp,-1,sizeof(dp));
        ans-=(1ll<<i);
        if(solve(1)>y)
            ans+=(1ll<<i);
    }
    cout<<ans<<endl;
}