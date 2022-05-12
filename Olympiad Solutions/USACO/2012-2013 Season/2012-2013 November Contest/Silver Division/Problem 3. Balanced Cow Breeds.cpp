//USACO 2012 November Contest, Silver
//Problem 3. Balanced Cow Breeds
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=1e3+9,mod=2012;
int n,dp[inf][inf+inf];
string a;
int solve(int pos,int sum1,int sum2){

    if(sum1<0 || sum2<0)
        return 0;

    if(pos==n+1)
        return (sum1==0 && sum2==0);

    int &ret=dp[pos][sum1+inf];
    if(ret!=-1)
        return ret;
    return ret=(solve(pos+1,sum1+(a[pos]=='('?1:-1),sum2)+solve(pos+1,sum1,sum2+(a[pos]=='('?1:-1)))%mod;
}

int main(){

    freopen("bbreeds.in","r",stdin);
    freopen("bbreeds.out","w",stdout);

    cin>>a;
    n=a.size();
    a=" "+a;
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0,0)<<endl;

}