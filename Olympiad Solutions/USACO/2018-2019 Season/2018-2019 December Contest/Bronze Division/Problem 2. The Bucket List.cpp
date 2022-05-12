
//USACO 2018 December Contest, Bronze
//Problem 2. The Bucket List
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9;
int par[inf];
int main(){
    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        par[a]+=c;
        par[b+1]-=c;
    }
    int mx=0;
    for(int i=1;i<inf;i++)
        par[i]+=par[i-1],mx=max(mx,par[i]);
    cout<<mx<<endl;
}