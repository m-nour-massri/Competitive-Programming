
//APIO 2014 Problem 2 Split the sequence
//1-4 subtasks solution 50 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e3+9,K=209,MX=1e9+9;
ll n,k,ans=-MX,idx;
ll pre[inf],a[inf];
pair<ll,ll> dp[inf][K];
vector<ll> split;

ll sum(ll x,ll y){
    return pre[y]-pre[x];
}

int main(){

    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i],pre[i]=pre[i-1]+a[i];

    for(ll j=1;j<=k;j++)
        for(ll i=1;i<=n;i++)
            for(ll z=0;z<i;z++)
                dp[i][j]=max(dp[i][j],make_pair(dp[z][j-1].first+sum(z,i)*sum(i,n),z));

    for(ll i=1;i<=n;i++)
        if(ans<dp[i][k].first)
            ans=dp[i][k].first,idx=i;

    split.push_back(idx);
    for(ll j=k;j>1;j--)
        idx=dp[idx][j].second,split.push_back(idx);

    reverse(split.begin(),split.end());

    cout<<ans<<endl;
    for(auto o:split)
        cout<<o<<" ";
    cout<<endl;
}