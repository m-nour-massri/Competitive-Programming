//USACO 2015 December Contest, Gold
//Problem 2. Fruit Feast
#include <bits/stdc++.h>
using namespace std;
const int inf=5e5+9;
int a,b,t,dp[inf][2],ans;

int solve(int i,bool is){
    ans=max(ans,i);
    int &ret=dp[i][is];
    if(ret!=-1)
        return ret;
    if(i+a<=t)
        ret=max(ret,a+solve(i+a,is));
    if(i+b<=t)
        ret=max(ret,b+solve(i+b,is));
    if(is)
        ret=max(ret,-i/2+solve(i/2,0));
    return ret;
}

int main(){

    freopen("feast.out","w",stdout);
    freopen("feast.in","r",stdin);
    cin>>t>>a>>b;

    memset(dp,-1,sizeof(dp));
    cout<<max(ans,solve(0,1));
}
