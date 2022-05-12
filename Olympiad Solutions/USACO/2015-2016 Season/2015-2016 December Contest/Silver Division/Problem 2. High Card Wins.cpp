
//USACO 2015 December Contest, Silver
//Problem 2. High Card Wins
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf],vis[inf];
int main(){
    freopen("highcard.out","w",stdout);
    freopen("highcard.in","r",stdin);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i],vis[a[i]]=1;
    set<int> s;
    sort(a+1,a+1+n);
    for(int i=1;i<=n+n;i++)
        if(!vis[i])
            s.insert(i);

    int ans=0;
    for(int i=1;i<=n;i++){
        auto o=s.lower_bound(a[i]);
        if(o!=s.end())
            ans++,s.erase(o);

    }
    cout<<ans<<endl;
}
