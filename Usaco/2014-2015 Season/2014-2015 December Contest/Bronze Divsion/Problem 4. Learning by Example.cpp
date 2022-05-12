
//USACO 2014 December Contest, Bronze
//Problem 4. Learning by Example
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=5e4+9;
pair<ll,ll> a[inf];
ll n,x,y,sum;

ll inter(ll l,ll r){

    ll d=min(r,y),f=max(l,x);
    if(d>=f)
        return d-f+1;
    return 0;
}

int main(){


    freopen("learning.out","w",stdout);
    freopen("learning.in","r",stdin);
    cin>>n>>x>>y;

    for(ll i=1;i<=n;i++){
        string s;
        ll te;
        cin>>s>>te;
        a[i]=make_pair(te,(s=="S"?1:0));
    }
    a[0]=make_pair(-1e9,0);
    a[n+1]=make_pair(2e9,0);
    sort(a+1,a+1+n);

    for(ll i=1;i<=n;i++){

        ll mid=a[i-1].first+a[i].first;

        mid/=2;
        mid++;

        if(a[i].second)
            sum+=inter(mid,a[i].first);
        mid=a[i].first+a[i+1].first;
        if(mid%2==0)
            mid/=2,mid--;
        else
            mid/=2;
        if(a[i].second)
            sum+=inter(a[i].first,mid);

        if(a[i].second)
            sum-=inter(a[i].first,a[i].first);

        if(i<n && (a[i].first+a[i+1].first)%2==0 && a[i].second|a[i+1].second)
            sum+=inter((a[i].first+a[i+1].first)/2,(a[i].first+a[i+1].first)/2);
    }
    cout<<sum<<endl;
}