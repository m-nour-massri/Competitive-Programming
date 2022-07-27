#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9,MX=1e9+9;
int n,a[inf],k,ans;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x = k-i+1;
        if(x >=0 && (x%2 == 0 || x>2))
            ans = max(ans,a[i]);
    }
    cout<<ans<<endl;
}