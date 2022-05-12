
//BOI 2019 Day 2 Problem 1 kitchen
//subtasks 4-4 21 points
#include <bits/stdc++.h>
using namespace std;
const int inf=42;
int n,m,k,sum,ans=1e9+9,mn=1e9+9;
int meals[inf],chefs[inf];
bool dp[inf][inf*inf][inf*inf];

void solve(int pos,int sum1,int sum2){

    if(sum1-sum>ans)
        return;

    if(sum1>=sum && sum2>=n*k)
        return void(ans=min(ans,sum1-sum));

    if(pos==m+1)
        return ;

    bool &ret=dp[pos][sum1][sum2];
    if(ret)
        return ;
    ret=1;
    solve(pos+1,sum1+chefs[pos],sum2+min(n,chefs[pos])),solve(pos+1,sum1,sum2) ;

}

int main(){

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>meals[i],sum+=meals[i],mn=min(mn,meals[i]);

    for(int i=1;i<=m;i++)
        cin>>chefs[i];

    if(mn<k)
        cout<<"Impossible"<<endl,exit(0);

    solve(1,0,0);

    if(ans>=1e9+9)
        cout<<"Impossible"<<endl,exit(0);
    cout<<ans<<endl;
}