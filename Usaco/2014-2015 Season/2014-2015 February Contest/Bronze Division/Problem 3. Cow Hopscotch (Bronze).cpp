//USACO 2015 February Contest, Bronze
//Problem 3. Cow Hopscotch (Bronze)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=19;
ll a[inf][inf],dp[inf][inf];
int main(){


    freopen("hopscotch.in","r",stdin);
    freopen("hopscotch.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        string temp;
        cin>>temp;
        for(ll j=1;j<=m;j++)
            a[i][j]=(temp[j-1]=='R');
    }
    dp[1][1]=1;
    for(ll i=1;i<=n;i++){

        for(ll j=1;j<=m;j++){

            for(ll z=1;z<i;z++)
                for(ll x=1;x<j;x++)
                    if(a[z][x]!=a[i][j])
                        dp[i][j]+=dp[z][x];
        }

    }

    cout<<dp[n][m]<<endl;
}