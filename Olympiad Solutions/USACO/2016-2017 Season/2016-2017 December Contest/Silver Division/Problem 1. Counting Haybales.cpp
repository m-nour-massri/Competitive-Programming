//USACO 2016 December Contest, Silver
//Problem 1. Counting Haybales
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf];
int main(){
    freopen("haybales.out","w",stdout),freopen("haybales.in","r",stdin);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    while(q--){
        int x,y;
        cin>>x>>y;
        int l=lower_bound(a+1,a+1+n,x)-a;
        int r=upper_bound(a+1,a+1+n,y)-a;
        r--;
        cout<<r-l+1<<endl;
    }
}
