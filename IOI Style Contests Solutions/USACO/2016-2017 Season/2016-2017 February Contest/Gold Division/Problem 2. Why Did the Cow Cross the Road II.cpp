//USACO 2017 February Contest, Gold
//Problem 2. Why Did the Cow Cross the Road II
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9;
int a[inf],b[inf],n,pos[inf],dp[inf][inf];
vector<int> v[inf];
int solve(int i,int last){

    if(i==n+1)
        return 0;

    int &ret=dp[i][last];
    if(ret!=-1)
        return ret;
    ret=solve(i+1,last);

    int z=upper_bound(v[i].begin(),v[i].end(),last)-v[i].begin();
    for(int j=z;j<v[i].size();j++)
        ret=max(ret,1+solve(i+1,v[i][j]));

    return ret;
}

int main(){

    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i],pos[b[i]]=i;

    for(int i=1;i<=n;i++){

        for(int j=max(1,a[i]-4);j<=min(n,a[i]+4);j++)
            v[i].push_back(pos[j]);

        sort(v[i].begin(),v[i].end());
    }

    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)<<endl;
}