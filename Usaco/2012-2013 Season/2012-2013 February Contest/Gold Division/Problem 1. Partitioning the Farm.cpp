//USACO 2013 February Contest, Gold
//Problem 1. Partitioning the Farm
#include <bits/stdc++.h>
using namespace std;
const int inf=16,MX=1e9+9;
int n,k,par[inf][inf];

int dp[inf][(1<<15)][inf+inf];
int mem[inf][inf][(1<<15)];

int sum(int x1,int y1,int x2,int y2){
    return par[x2][y2]-par[x2][y1-1]-par[x1-1][y2]+par[x1-1][y1-1];
}

int calc(int x1,int x2,int mask){

    int &ret=mem[x1][x2][mask];
    if(ret != -1)
        return ret;

    ret=0;
    int last=0;
    for(int i=1;i<=n;i++)
        if( (1<<(i-1)) & mask )
            ret=max(ret,sum(x1,last+1,x2,i)),last=i;
    ret=max(ret,sum(x1,last+1,x2,n));
    return ret;
}

int solve(int row,int mask,int rem){

    if(row == n+1)
        return 0;
    if(rem < 0)
        return MX;

    int &ret=dp[row][mask][rem];
    if(ret != -1)
        return ret;
    ret = MX;
     for(int i=1;i<n ;i++)
        if( ((1<<(i-1)) & mask) == 0 )
            ret=min( ret, solve(row,mask | (1<<(i-1)) , rem-1) );
     for(int i=row;i<=n;i++)
        ret = min( ret , max(calc(row,i,mask),solve(i+1,mask,rem-1)));
     return ret;
}

int main(){

    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>par[i][j],par[i][j]+=par[i-1][j]+par[i][j-1]-par[i-1][j-1];

    memset(dp,-1,sizeof(dp));
    memset(mem,-1,sizeof(mem));
    cout<<solve(1,0,k)<<endl;
}