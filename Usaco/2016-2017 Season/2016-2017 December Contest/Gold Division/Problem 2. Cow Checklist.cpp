//USACO 2016 December Contest, Gold
//Problem 2. Cow Checklist
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9;
pair<long long ,long long > a[inf],b[inf];
long long  dp[inf][inf][2],n,m;

long long  dis(pair<long long ,long long > x,pair<long long ,long long > y){
    return abs(x.first-y.first)*abs(x.first-y.first)+abs(x.second-y.second)*abs(x.second-y.second);
}

long long  solve(long long  l,long long  r,bool s){
    if(l==n && r==m)
        return (s?1e18+9:0);

    long long  &ret=dp[l][r][s];
    if(ret!=-1)
        return ret;
    ret=1e18+9;

    if(l<n)
        ret=min(ret, solve(l+1,r,0)+(s?dis(a[l+1],b[r]):dis(a[l+1],a[l])  )  );

    if(r<m)
        ret=min(ret,solve(l,r+1,1)+(s?dis(b[r+1],b[r]):dis(a[l],b[r+1])  ));

    return ret;
}

int main(){
    freopen("checklist.out","w",stdout);freopen("checklist.in","r",stdin);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;

    for(long long  i=1;i<=m;i++)
        cin>>b[i].first>>b[i].second;


    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0,0)<<endl;
}
