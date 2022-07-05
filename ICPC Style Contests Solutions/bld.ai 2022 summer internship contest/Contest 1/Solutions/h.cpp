
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MX = 1e18+9,inf = 1e5+9;
int n,k,ans = -MX;
pair<int,int> pts[inf];
multiset<int> s;

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    int l = 1;
    for(int i=1;i<=n;i++){
        cin>>pts[i].first>>pts[i].second;
        while(pts[i].first - pts[l].first > k){
            s.erase(s.find(pts[l].second - pts[l].first));
            l++;
        }
        if(!s.empty())
            ans = max(ans,*s.rbegin() + pts[i].first + pts[i].second);
         s.insert(pts[i].second - pts[i].first);
    }
    if(ans <= -MX)
        ans = -1;
    cout<<ans<<endl;
}
