//USACO 2017 US Open Contest, Silver
//Problem 1. Paired Up
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int n,ans;
pair<int,int> a[inf];

int main(){

    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].second>>a[i].first;

    sort(a+1,a+1+n);

    int l=1,r=n;
    while(l<r){
        ans = max(ans,a[l].first+a[r].first);
        if(a[l].second > a[r].second)
            a[l].second -= a[r].second,r--;
        else if(a[l].second == a[r].second)
            l++,r--;
        else
            a[r].second -= a[l].second , l++;
    }
    if(l == r)
        ans =max(ans, a[l].first+a[l].first );
    cout<<ans<<endl;
}