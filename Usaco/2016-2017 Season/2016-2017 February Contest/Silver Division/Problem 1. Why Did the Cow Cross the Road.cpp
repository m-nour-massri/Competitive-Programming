//USACO 2017 February Contest, Silver
//Problem 1. Why Did the Cow Cross the Road
#include <bits/stdc++.h>
using namespace std;
const int inf=2e4+9;
int ch[inf];
pair<int,int> a[inf];
int main(){

    freopen("helpcross.out","w",stdout);
    freopen("helpcross.in","r",stdin);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>ch[i];

    for(int i=1;i<=m;i++)
        cin>>a[i].first>>a[i].second;

    sort(a+1,a+1+m);
    sort(ch+1,ch+1+n);
    int l=1,ans=0;
    multiset<int> s;

    for(int i=1;i<=n;i++){

        while(a[l].first<=ch[i] && l<=m)
            s.insert(a[l++].second);

        while(!s.empty() && *s.begin()<ch[i])
            s.erase(s.begin());

        if(!s.empty())
            s.erase(s.begin()),ans++;
    }

    cout<<ans<<endl;
}