
//APIO 2015 Bali Sculptures
//2-2 subtasks solution 16 points
#include <bits/stdc++.h>
using namespace std;
const int N=55,B=22,O=522,MX=1e9+9;
int n,x,y,a[N],pre[N],dp[N][O][B];

int solve(int pos,int OR,int parts){

    if(pos==n+1)
        return (parts>=x && parts<=y?OR:MX);

    int &ret=dp[pos][OR][parts];
    if(ret!=-1)
        return ret;
    ret=MX;
    for(int i=pos;i<=n;i++)
        ret=min(ret,solve(i+1,OR|(pre[i]-pre[pos-1]),parts+1));
    return ret;
}

int main(){

    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
        cin>>a[i],pre[i]=a[i]+pre[i-1];

    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0,0)<<endl;
}