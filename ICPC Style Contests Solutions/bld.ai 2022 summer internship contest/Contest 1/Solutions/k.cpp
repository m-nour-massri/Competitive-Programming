#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf =1e5+9;
int n,k,ans;
int a[inf],pre[inf];
map<int,int> mp;

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    mp[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        if(mp.count(pre[i]-k))
            ans = max(ans,i-mp[pre[i]-k]);
        if(!mp.count(pre[i]) == 0)
            mp[pre[i]] = i;
    }
    cout<<ans<<endl;
}
