
//USACO 2018 December Contest, Gold
//Problem 3. Teamwork
#include <bits/stdc++.h>
using namespace std;
const int inf=1e4+9;
int a[inf],dp[inf],n,k;

int solve(int pos){
    if(pos==n+1)
        return 0;

    int &ret=dp[pos];
    if(ret!=-1)
        return ret;

    int mx=a[pos];
    ret=a[pos]+solve(pos+1);
    for(int i=pos+1;i<=min(pos+k-1,n);i++){
        mx=max(mx,a[i]);
        ret=max(ret,(i-pos+1)*mx+solve(i+1));
    }
    return ret;
}

int main(){

    freopen("teamwork.out","w",stdout);
    freopen("teamwork.in","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    memset(dp,-1,sizeof(dp));
    cout<<solve(1)<<endl;
}