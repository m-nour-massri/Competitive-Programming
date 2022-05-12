//USACO 2018 US Open Contest, Gold
//Problem 3. Talent Show
//binary search with dp
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int inf=255,MAXW=1e3+9;
pair<int,int> a[inf];
long long  n,w,dp[inf][MAXW],te;

long long solve(long long pos,long long left){
    if(pos==n+1)
        return (left==0?0:-1e18-99);

    long long &ret=dp[pos][left];
    if(ret!=-1)
        return ret;
    long long ch1=solve(pos+1,left);
    long long cal=1000ll*a[pos].second-te*a[pos].first;
    long long ch2=cal+solve(pos+1,max(left-a[pos].first,0ll)) ;
    ret=max(ch1,ch2);
    return ret ;
}

bool check(long long s){
        memset(dp,-1,sizeof(dp));
        te=s;
        long long x=solve(1ll,w);
        return x>=0;
}

int  main(){
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    cin>>n>>w;
    for(long long i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;

    long long l=0,r=25e7+9;
    while(r-l>1){
        if(check(mid))
            l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}