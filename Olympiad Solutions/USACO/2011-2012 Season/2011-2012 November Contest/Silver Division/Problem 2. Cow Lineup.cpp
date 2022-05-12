
//USACO 2011 November Contest, Silver Division Problem 2. Cow Lineup
#include <bits/stdc++.h>
using namespace std;
const int inf=5e4+9;
pair<int,int> a[inf];int n,di,r=1,ans=1e9+9;
set<int> s;
map<int,int>mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second,s.insert(a[i].second);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        while(r<=n && di<s.size()){
            if(mp[a[r].second]==0)
                    di++;
            mp[a[r].second]++;
            r++;
        }
        if(di==s.size())
                ans=min(ans,a[r-1].first-a[i].first);
        mp[a[i].second]--;
        if(mp[a[i].second]==0)
            di--;
    }
    cout<<ans<<endl;
}