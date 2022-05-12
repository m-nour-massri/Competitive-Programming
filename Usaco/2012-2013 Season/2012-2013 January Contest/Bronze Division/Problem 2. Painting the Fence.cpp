//USACO 2013 January Contest, Bronze
//Problem 2. Painting the Fence
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=3e5+9;
ll n,k,cnt,sum,ans;
ll a[inf],val[inf],pre[inf];
char dir[inf];
map<ll,ll> mp;
int main(){

    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);

    cin>>n;
    k=2;
    mp[sum],mp[sum-1],mp[sum+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i]>>dir[i]  ,a[i]*=(dir[i]=='L'?-1:1),sum+=a[i],mp[sum],mp[sum+1],mp[sum-1];

    for(auto &o:mp)
        o.second=++cnt,val[cnt]=o.first;

    sum=0;
    for(ll i=1;i<=n;i++){
        ll l=sum,r=sum+a[i];
        if(l>r )
            swap(l,r);

        pre[mp[l+1]]++,pre[mp[r+1]]--;
        //because we want to count the distance not the positions so pre[i] equal to the number of
        //till i before adding the elements of i so if pre[i]>=k we can add the distance between i and i-1
        sum+=a[i];
    }

    for(ll i=1;i<=cnt;i++)
        pre[i]+=pre[i-1];

    ll last=-1;
    for(ll i=1;i<=cnt;i++){
        if(i>1 && pre[i]>=k)
            ans+=val[i]-val[i-1];
    }
    cout<<ans<<endl;
}