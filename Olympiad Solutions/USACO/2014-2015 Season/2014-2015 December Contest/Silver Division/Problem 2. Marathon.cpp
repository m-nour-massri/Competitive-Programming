
//USACO 2014 December Contest, Silver
//Problem 2. Marathon
#include <bits/stdc++.h>
using namespace std;
const int inf=509,MX=1e9+9;
pair<int,int> a[inf];
int dp[inf][inf],n,k;

int dis(int i,int j){

    return abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
}

int solve(int pos,int left){

    if(left<0)
        return MX;

    if(pos==n)
        return 0;

    int &ret=dp[pos][left];
    if(ret!=-1)
        return ret;

    ret=MX;
    for(int i=pos+1;i<=min(n,pos+left+1);i++)
        ret=min(ret,dis(pos,i)+solve(i,left-(i-pos-1)));
    return ret;
}

int main(){


    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;

    memset(dp,-1,sizeof(dp));
    cout<<solve(1,k)<<endl;
}

