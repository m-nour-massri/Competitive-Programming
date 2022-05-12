//USACO 2015 February Contest, Bronze
//Problem 2. COW
#include <bits/stdc++.h>
#define le node+node
#define ri node+node+1
#define mid (l+r)/2
#define ll long long
using namespace std;

int main(){

    freopen("cow.in","r",stdin);
    freopen("cow.out","w",stdout);
    ll n;
    string a;
    cin>>n>>a;
    ll cnt_w=0,cnt_o=0,ans=0;

    for(ll i=n-1;i>=0;i--){

        if(a[i]=='W')
            cnt_w++;

        else if(a[i]=='O')
            cnt_o+=cnt_w;

        else if(a[i]=='C')
            ans+=cnt_o;
    }
    cout<<ans<<endl;
}