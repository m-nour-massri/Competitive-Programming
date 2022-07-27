#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5+9;
int n,a[inf],ans[inf],mn = 1e9+9;
map<int,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=n;i>=1;i--){
        mp[a[i]]++;
        mn = min(mn,a[i]);
        ans[i] = mp[mn];
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}