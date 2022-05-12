//USACO 2016 January Contest, Silver
//Problem 2. Subsequences Summing to Sevens
#include <bits/stdc++.h>
using namespace std;
int last[55];
int main(){

    freopen("div7.out","w",stdout);
    freopen("div7.in","r",stdin);

    int n,ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int te;
        cin>>te;
        sum=(sum+te)%7;
        if(last[sum])
            ans=max(ans,i-last[sum]);
        else
            last[sum]=i;
    }
    cout<<ans<<endl;
}