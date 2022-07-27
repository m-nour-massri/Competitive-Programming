#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e5+9;
int n,k,a[inf],pre[inf],ans = 0;
map<int,int> mp;

signed main(){
    cin>>n>>k;
    mp[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i],pre[i] = a[i] + pre[i-1];
        int md = pre[i]%k;
        if(mp.find(md) != mp.end())
            ans = max(ans,i - mp[md]);
        else
            mp[md] = i;
    }
    cout<<ans<<endl;
}