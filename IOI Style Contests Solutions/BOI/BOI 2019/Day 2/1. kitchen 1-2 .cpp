//BOI 2019 Day 2 Problem 1 kitchen
//subtasks 1-2 31 points
#include <bits/stdc++.h>
using namespace std;
const int inf=3e2+9;
int n,m,k,sum,ans=1e9+9,mn=1e9+9;
int meals[inf],chefs[inf];

int main(){

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>meals[i],sum+=meals[i],mn=min(mn,meals[i]);

    for(int i=0;i<m;i++)
        cin>>chefs[i];

    if(mn<k)
        cout<<"Impossible"<<endl,exit(0);

    for(int i=0;i<(1<<m);i++){

        int sum1=0,sum2=0;
        for(int j=0;j<m;j++)
            if(i&(1<<j))
                sum1+=chefs[j],sum2+=min(chefs[j],n);

            if(sum1<sum  || __builtin_popcount(i)<k || sum2<n*k)
                continue;
            ans=min(ans,sum1-sum);
    }
    if(ans>=1e9+9)
        cout<<"Impossible"<<endl,exit(0);
    cout<<ans<<endl;
}