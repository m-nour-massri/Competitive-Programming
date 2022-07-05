
//BOI 2019 Day 2 Problem 1 kitchen
//subtasks 3-3
#include <bits/stdc++.h>
using namespace std;
const int inf=3e2+9;
int n,m,k,sum,ans=1e9+9,mn=1e9+9;
int meals[inf],chefs[inf],dp[inf][inf*inf];

int solve(int pos,int taken){

    if(pos==m+1)
        return (taken>=sum?taken-sum:1e9+9);

    int &ret=dp[pos][taken];
    if(ret!=-1)
        return ret;
    ret=1e9+9;
    ret=min(solve(pos+1,taken+chefs[pos]),solve(pos+1,taken));
    return ret;
}

int main(){

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>meals[i],sum+=meals[i];

    for(int i=1;i<=m;i++)
        cin>>chefs[i];

    memset(dp,-1,sizeof(dp));
    ans=solve(1,0);

    if(ans>=1e9+9)
        cout<<"Impossible"<<endl,exit(0);
    cout<<ans<<endl;
}