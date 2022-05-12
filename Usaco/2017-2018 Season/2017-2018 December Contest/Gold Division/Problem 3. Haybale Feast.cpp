//USACO 2017 December Contest, Gold
//Problem 3. Haybale Feast
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e5+9,I=22;
ll a[inf],b[inf],par[inf],sparse[inf][I],n,m;

void preprocesssing(){
    for(ll i=0;i<n;i++)
        sparse[i][0]=b[i];

    for(ll j=1;(1<<j)<=n;j++)
        for(ll i=0;i+(1<<j)-1<n;i++)
            sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);

}

ll query(ll l,ll r){
    ll s=r-l+1,ans=-1e18-9;
    for(ll i=I-1;i>=0;i--)
        if(s & (1<<i))
            ans=max(ans,sparse[l][i]),l+=(1<<i);
    return ans;
}

int main(){

    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i]>>b[i],par[i]=par[i-1]+a[i];

    preprocesssing();

    ll ans=1e18;
    for(ll i=3;i<=n;i++){
        ll s=par[i-1]+m;
        ll id=lower_bound(par+1,par+1+n,s)-par;
        if(par[id]>=s)
            ans=min(ans, query(i,id) );

    }
    cout<<ans<<endl;
}