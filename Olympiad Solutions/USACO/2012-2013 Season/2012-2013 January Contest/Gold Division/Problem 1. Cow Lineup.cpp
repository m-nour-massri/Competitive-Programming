//USACO 2013 January Contest, Gold
//Problem 1. Cow Lineup
//two pointers
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int n,k,cnt,ans;
int a[inf],frequency[inf];
map<int,int> mp;
multiset<int> s;
int main(){

    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin>>n>>k;
    k++;
    for(int i=1;i<=n;i++)
        cin>>a[i],mp[a[i]];

    for(auto &o:mp)
        o.second=++cnt;

    for(int i=1;i<=n;i++)
        a[i]=mp[a[i]];
    mp.clear();

    int r=0,DiffCnt=0;
    for(int i=1;i<=n;i++){
        while(r<n && DiffCnt+(frequency[a[r+1]]==0 )<=k ){
            DiffCnt+=(frequency[a[r+1]]==0);
            r++;
            frequency[a[r]]++;
            if(frequency[a[r]]>1)
                s.erase(s.find(frequency[a[r]]-1));
            s.insert(frequency[a[r]]);
        }
        ans=max(ans,*s.rbegin());
        s.erase(s.find(frequency[a[i]]));
        frequency[a[i]]--;
        DiffCnt-=(frequency[a[i]]==0);
        if(frequency[a[i]]>0)
            s.insert(frequency[a[i]]);
    }
    cout<<ans<<endl;
}