//BOI 2019 Day 2 Problem 1 kitchen
//subtasks 4-4 21 points
#include <bits/stdc++.h>
using namespace std;
const int inf=309,MX=1e9+9;
int n,m,k,sum,mn=1e9+9;
int meals[inf],chefs[inf];
int dp[inf][inf*inf];

int solve(int pos,int sum1){

    if(sum1 == 0)
        return 0;

    if( pos == m+1 || sum1<0)
        return -MX;
    int &ret=dp[pos][sum1];
    if(ret != -1)
        return ret;
    ret = 0;
    ret = max( solve(pos+1,sum1-chefs[pos])+min( chefs[pos],n ) ,solve(pos+1,sum1));
    return ret;
}

int main(){

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>meals[i],sum+=meals[i],mn=min(mn,meals[i]);

    for(int i=1;i<=m;i++)
        cin>>chefs[i];

    if(mn<k)
        cout<<"Impossible"<<endl,exit(0);

    memset(dp,-1,sizeof(dp));
    for(int i=sum;i<inf*inf;i++)
        if( solve( 1,i) >=n*k )
            cout<<i-sum<<endl,exit(0);

    cout<<"Impossible"<<endl;
}