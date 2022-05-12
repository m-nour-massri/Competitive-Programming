
//USACO 2014 December Contest, Bronze
//Problem 1. Marathon
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
pair<long long ,long long > a[inf];
long long  pre[inf],suf[inf],ans=1e18+9;

long long  dis(long long  x,long long  y){

    return abs(a[x].first-a[y].first)+abs(a[x].second-a[y].second);
}

int main(){

    freopen("marathon.out","w",stdout);
    freopen("marathon.int","r",stdin);

    long long  n;
    cin>>n;
    for(long long  i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second,pre[i]=pre[i-1]+(i==1?0:dis(i,i-1));

    for(long long  i=n-1;i>=1;i--)
        suf[i]=suf[i+1]+dis(i,i+1);

    for(long long  i=1;i<=n-2;i++)
        ans=min(ans,pre[i]+suf[i+2]+dis(i,i+2));

    cout<<ans<<endl;
}
