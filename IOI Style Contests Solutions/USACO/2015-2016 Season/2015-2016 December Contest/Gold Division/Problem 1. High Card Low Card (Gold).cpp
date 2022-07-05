//USACO 2015 December Contest, Gold
//Problem 1. High Card Low Card (Gold)
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf],vis[inf],b[inf];
int main(){
    freopen("cardgame.in","r",stdin);freopen("cardgame.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=1;
    }
    int l=1;
    for(int i=1;i<=n+n;i++)
        if(!vis[i])
            b[l++]=i;

    set<int>s;
    for(int i=n/2+1;i<=n;i++)
        s.insert(b[i]);

    for(int i=1;i<=n/2;i++){
        auto o=s.lower_bound(a[i]);
        if(o!=s.end())
            s.erase(o),ans++;
    }
    s.clear();
    for(int i=1;i<=n/2;i++)
        s.insert(-b[i]);
    for(int i=n/2+1;i<=n;i++){
        auto o=s.lower_bound(-a[i]);
        if(o!=s.end())
            s.erase(o),ans++;
    }
    cout<<ans<<endl;
}