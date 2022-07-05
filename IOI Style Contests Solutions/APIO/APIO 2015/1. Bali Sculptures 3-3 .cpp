//APIO 2015 Bali Sculptures
//3-3 subtasks solution 21 points
#include <bits/stdc++.h>
using namespace std;
const int N=105,O=(1<<13)+9,MX=1e9+9;
int n,x,y,a[N],pre[N],dp[N][O];

int solve(int pos,int OR){ // we don't want any zero-bits in OR to be set desired partition

    if(pos==n+1)
        return 0;

    int &ret=dp[pos][OR];
    if(ret!=-1)
        return ret;
    ret=MX;
    for(int i=pos;i<=n;i++)
        if( (OR & (pre[i]-pre[pos-1])) ==0  )
            ret=min(ret,solve(i+1,OR)+1);
    return ret;
}

int reversed(int num){//we reverse all the bits up to the 12-th bit

    int ret=0;
    for(int i=0;i<=12;i++)
        if( (num&(1<<i))==0 )
            ret|=(1<<i);
    return ret;
}

int main(){

    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)
        cin>>a[i],pre[i]=a[i]+pre[i-1];

    memset(dp,-1,sizeof(dp));

    for(int i=0;i<(1<<12);i++)
        if(solve(1,reversed(i))<=y)
            cout<<i<<endl,exit(0);
    // we want only the set-bits in OR to be set in the desired partition so reverse all bits in i and check
    // in the DP if reversed(i) & sum equal to zero or not
}