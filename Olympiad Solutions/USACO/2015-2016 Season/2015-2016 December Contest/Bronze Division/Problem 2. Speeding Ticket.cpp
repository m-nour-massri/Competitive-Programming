//USACO 2015 December Contest, Bronze
//Problem 2. Speeding Ticket
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int sp[inf];
int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int l=1,ans=0;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        while(x--)
            sp[l++]=y;
    }
    l=1;

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        while(x--)
            ans=max(ans,y-sp[l++]);
    }
    cout<<ans<<endl;
}