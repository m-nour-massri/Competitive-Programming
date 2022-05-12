//USACO 2017 January Contest, Gold
//Problem 2. Hoof, Paper, Scissors
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9,MX=1e9+9;
int n,k,a[inf],dp[inf][5][22];

int solve(int pos,int cur,int rem){

    if(rem<0)
        return -MX;

    if(pos==n+1)
        return 0;

    int &ret=dp[pos][cur][rem];
    if(ret!=-1)
        return ret;

    for(int i=0;i<3;i++)
        ret=max(ret,solve(pos+1,i,rem-(i!=cur))+(i==a[pos])  );

    return ret;
}

int main(){

    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
	
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        char ty[3];
        scanf("%s",ty);
        if(ty[0]=='P')
            a[i]=1;
        else if(ty[0]=='S')
            a[i]=2;
        else
            a[i]=0;
    }
    memset(dp,-1,sizeof(dp));
    cout<<max(solve(1,1,k),max(solve(1,2,k),solve(1,0,k)));
}