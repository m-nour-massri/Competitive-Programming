//USACO 2016 January Contest, Silver
//Problem 1. Angry Cows
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
using namespace std;
const int inf=5e4+9;
ll a[inf],n,k;

bool check(ll x){

    ll last=a[1],rem=k-1;
    for(ll i=2;i<=n;i++){
        if(a[i]>x*2+last)
            last=a[i],rem--;
        if(rem<0)
            return 0;
    }
    return 1;
}

int main(){

    freopen("angry.out","w",stdout);
    freopen("angry.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);
    ll l=0,r=1e9+7;
    while(r-l>1){
        if(check(mid))
            r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}