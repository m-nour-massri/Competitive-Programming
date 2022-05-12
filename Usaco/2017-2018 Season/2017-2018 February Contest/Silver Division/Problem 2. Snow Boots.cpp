
//USACO 2018 February Contest, Silver
//Problem 2. Snow Boots
#include <bits/stdc++.h>
using namespace std;
const int inf=259;
int a[inf],n,m,dp[inf][inf];
pair<int,int> bo[inf];

int solve(int pos,int boot){
    if(pos==n)
        return 0;
    int &ret=dp[pos][boot];
    if(ret!=-1)
        return ret;
    ret=1e9;
    for(int i=pos+1;i<=min(pos+bo[boot].second,n);i++)
        if(a[i]<=bo[boot].first)
            ret=min(ret,solve(i,boot));
    for(int i=boot+1;i<=m;i++)
        if(a[pos]<=bo[i].first)
            ret=min(ret,i-boot+solve(pos,i));
    return ret;
}

int main(){
    //freopen("snowboots.in","r",stdin);freopen("snowboots.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>bo[i].first>>bo[i].second;
    memset(dp,-1,sizeof(dp));

    cout<<solve(1,1)<<endl;
}