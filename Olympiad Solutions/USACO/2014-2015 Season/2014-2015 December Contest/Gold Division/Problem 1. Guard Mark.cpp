
//USACO 2014 December Contest, Gold
//Problem 1. Guard Mark
//DP bit masking problem
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=22,MX=1e18+9;
ll n,k,w[inf],s[inf],h[inf],dp[(1<<inf)];

ll solve(ll mask){

    int pos=__builtin_popcount(mask),height=0,weight=0;
    for(int i=0;i<n;i++)
        if( ((1<<i)&mask ))
            height+=h[i],weight+=w[i];

    if(pos==n)
        return (-MX);

    ll &ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=-MX;

    for(ll i=0;i<n;i++){

        if(mask&(1<<i))
            continue;
        if(s[i]>=weight){
            if(h[i]+height>=k)
                ret=max(ret,s[i]-weight);
            else
                ret=max(ret,min(s[i]-weight,solve(mask|(1<<i))  ));
        }
    }
    return ret;
}

int main(){

    freopen("guard.out","w",stdout);
    freopen("guard.in","r",stdin);
    cin>>n>>k;
    for(ll i=0;i<n;i++)
        cin>>h[i]>>w[i]>>s[i];

    memset(dp,-1,sizeof(dp));
    ll ans=solve(00);
    if(ans<0)
        cout<<"Mark is too tall"<<endl;
    else cout<<ans<<endl;
}