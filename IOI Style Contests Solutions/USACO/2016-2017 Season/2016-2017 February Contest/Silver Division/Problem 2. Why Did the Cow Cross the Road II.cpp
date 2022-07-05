//USACO 2017 February Contest, Silver
//Problem 2. Why Did the Cow Cross the Road II
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int par[inf],te;
int main(){

    freopen("maxcross.out","w",stdout);
    freopen("maxcross.in","r",stdin);
    int n,k,m,ans=1e9;
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++)
        cin>>te,par[te]++;

    for(int i=1;i<=n;i++)
        par[i]+=par[i-1];

    for(int i=k;i<=n;i++)
        ans=min(ans,par[i]-par[i-k]);

    cout<<ans<<endl;
}