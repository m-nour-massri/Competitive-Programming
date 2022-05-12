//APIO 2015 Bali Sculptures
//1-1 subtasks solution 9 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=22,MX=1e18+9;
ll n,x,y,ans=MX,a[inf],pre[inf];

int main(){

    cin>>n>>x>>y;
    for(ll i=0;i<n;i++)
        cin>>a[i],pre[i]=a[i]+(i>0?pre[i-1]:0);

    for(ll i=0;i<(1<<(n-1));i++){
        ll mask=i|(1<<(n-1));
        ll cnt=__builtin_popcountll(mask);
        if(cnt>y || cnt<x)
            continue;

        ll OR=0,last=0;
        for(ll j=0;j<n;j++)
            if((1<<j) & mask )
                OR|=(pre[j]-pre[last]+a[last]),last=j+1;
        ans=min(ans,OR);
    }
    cout<<ans<<endl;
}