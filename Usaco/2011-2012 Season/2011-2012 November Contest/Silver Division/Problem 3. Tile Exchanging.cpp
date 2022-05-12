//USACO 2011 November Contest, Silver Division Problem 3. Tile Exchanging
#include <bits/stdc++.h>
using namespace std;
const int inf=1e4+9;
int a[12],dp[19][inf],n,m;
int solve(int pos,int rem){
    if(pos==n+1)
        return (rem==0? 0: 1e9+9);

    int &ret=dp[pos][rem];
    if(ret!=-1)
        return ret;
    ret=1e9+9;
    for(int i=1;i<=100;i++)
        if(rem>=i*i)
            ret=min(ret,abs(a[pos]-i)*abs(a[pos]-i) +solve(pos+1,rem-(i*i)));

    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int x=solve(1,m);
    if(x>=1e9)
        x=-1;
    cout<<x<<endl;

}