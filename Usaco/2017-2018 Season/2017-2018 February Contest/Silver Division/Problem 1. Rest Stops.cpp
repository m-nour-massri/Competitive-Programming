
//USACO 2018 February Contest, Silver
//Problem 1. Rest Stops
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
pair<long long ,long long > a[inf],mx[inf];
long long  pos[inf*10];
int main(){
    freopen("reststops.in","r",stdin);freopen("reststops.out","w",stdout);
    long long  n,x,y,l;
    cin>>l>>n>>x>>y;
    for(long long  i=1;i<=n;i++)
        cin>>a[i].second>>a[i].first,pos[a[i].second]=i;

    for(long long  i=n;i>=1;i--)
        mx[i]=max(mx[i+1],a[i]);

    long long  xcur=0,ycur=0,xx=0,ans=0;
    while(xx<n){
        pair<long long ,long long > p=mx[xx+1];
        xx=pos[p.second];
        ans+=((p.second-xcur)*x-(p.second-ycur)*y )*p.first;
        xcur=ycur=p.second;
    }
    cout<<ans<<endl;
}