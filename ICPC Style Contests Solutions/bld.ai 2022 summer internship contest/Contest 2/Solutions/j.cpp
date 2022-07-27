#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 22,mod = 1e9+7;
int n,a[inf][inf],dp[(1<<21)+44];

int solve(int i,int mask){
    if(mask == (1<<n)-1)
        return 1;
    int &ret = dp[mask];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int j=0;j<n;j++){
        if(mask & (1<<j) || !a[i][j])
            continue;
        ret = (ret + solve(i+1,mask|(1<<j)))%mod;
    }
    return ret;
}

signed main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<endl;
}