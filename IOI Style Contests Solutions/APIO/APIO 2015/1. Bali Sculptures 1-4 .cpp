
//APIO 2015 Bali Sculptures
//1-4 subtasks solution 71 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=105;
ll n,x,y,a[N],pre[N],dp[N][N];
ll ans ;

ll solve(ll pos,ll cuts){

    if( pos == n+1)
        return  (cuts>=x && cuts<=y);

    ll &ret=dp[pos][cuts];
    if(ret != -1)
        return ret;
    ret = 0;
    for(ll i=pos;i<=n;i++)
        if( ( (pre[i]-pre[pos-1]) | ans ) == ans )// we don't want set-bits that are not set in ans
            ret |= solve(i+1,cuts+1) ;
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
        if(!solve(1,0))
            ans+=(1ll<<i);
    }
    cout<<ans<<endl;
}