//USACO 2014 December Contest, Bronze
//Problem 3. Cow Jog
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e5+9,MX=1e18+9;
ll n,s,x[inf],t[inf],ans;
int main(){

    freopen("cowjog.out","w",stdout);
    freopen("cowjog.in","r",stdin);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>x[i]>>t[i];

    ll mn=MX;
    for(ll i=n;i>=1;i--){
        if(t[i]<=mn)
            mn=t[i],ans++;
    }
    cout<<ans<<endl;
}