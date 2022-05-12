//USACO 2014 December Contest, Silver
//Problem 3. Cow Jog
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e5+9,MX=1e18+9;
ll n,s,x[inf],t[inf],ans;
int main(){

    freopen("cowjog.out","w",stdout);
    freopen("cowjog.in","r",stdin);
    cin>>n>>s;
    for(ll i=1;i<=n;i++)
        cin>>x[i]>>t[i];

    //when a cow slow down and join a running group all the group occupy the same point

    ll mn=MX;
    for(ll i=n;i>=1;i--){
        if(t[i]*s+x[i]<mn)
            mn=t[i]*s+x[i],ans++;
    }
    cout<<ans<<endl;
}