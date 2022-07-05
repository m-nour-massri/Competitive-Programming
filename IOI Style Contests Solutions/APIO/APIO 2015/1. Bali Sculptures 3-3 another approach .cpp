
//APIO 2015 Bali Sculptures
//3-3 subtasks solution 21 points
#include <bits/stdc++.h>
using namespace std;
const int N=105,O=(1<<13)+9,MX=1e9+9;
int n,x,y,a[N],pre[N],dp[N];
int cur ;
int solve(int pos){

    if( pos == n+1)
        return  0;

    int &ret=dp[pos];
    if(ret != -1)
        return ret;
    ret = MX;
    for(int i=pos;i<=n;i++)
        if( ( (pre[i]-pre[pos-1]) | cur ) == cur )// we don't want set-bits that are not set in cur
            ret = min(ret, solve(i+1)  +1 );
    return ret;
}

int main(){

    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
        cin>>a[i],pre[i]=a[i]+pre[i-1];

    for(cur=0;cur<(1<<12);cur++){
        memset(dp,-1,sizeof(dp));
        if(solve(1)<=y)
            cout<<cur<<endl,exit(0);
    }
}