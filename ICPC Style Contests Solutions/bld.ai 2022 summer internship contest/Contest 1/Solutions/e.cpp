#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf =1e5+9;
int n,h,a[inf];

bool check(int x){
    int tmp = 0;
    for(int i=1;i<=n;i++)
        tmp += (a[i]/x) + (a[i]%x > 0);
    return tmp <= h;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>h;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l = 0, r = 1e9;
    while(r-l>1){
        int mid = (l+r)/2;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout<<r<<endl;
}