//USACO 2017 US Open Contest, Gold
//Problem 3. Modern Art 2
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9,lg=20;
int n,ans,a[inf],sparse[inf][lg];
pair<int,int> intervals[inf];

set<pair<int,int> > s;
set<int> en;
int main(){

    freopen("art2.in","r",stdin);
        freopen("art2.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i] , intervals[ a[i] ].second = i ,
        intervals[ a[i] ].first = (intervals[ a[i] ].first == 0 ?i: intervals[ a[i] ].first),
        sparse[i][0]=a[i];

    for(int j=1;j<lg;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            sparse[i][j] = min(sparse[i][j-1] , sparse[i+(1<<(j-1) )][j-1]);

    for(int i=1;i<=n;i++){
        int x = intervals[i].first, y =intervals[i].second;
        if(intervals[i].first == 0)
            continue;

        int diff = y-x+1,tmp = x,mn=1e9+9;
        for(int j=lg-1;j>=0;j--)
            if(diff & (1<<j))
                mn = min(mn,sparse[tmp][j]) , tmp+=(1<<j);
        if(mn == 0)
            cout<<-1<<endl,exit(0);

        s.insert(make_pair(x,y));
    }


    for(auto o:s){
          if( !en.empty() && *en.rbegin() > o.first ){
          int t = *en.lower_bound(o.first);
          if(t <o.second)
            cout<<-1<<endl,exit(0);
          }
          en.insert(o.second);
    }

    while(!s.empty()){
        int cur = 0;
        while( !s.empty() &&  (*s.rbegin()).first >= cur){
            pair<int,int> p = *s.lower_bound(make_pair(cur,-1));
            s.erase(p);
            cur = p.second;
        }
        ans++;
    }
    cout<<ans<<endl;
}