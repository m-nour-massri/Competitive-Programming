//USACO 2017 January Contest, Silver
//Problem 1. Cow Dance Show
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
 const int inf=1e5+9;
int n,t,a[inf];

bool check(int k){
    multiset<int> s;
    for(int i=1;i<=k;i++)
        s.insert(a[i]);
    for(int i=k+1;i<=n;i++){
        int cur=*s.begin();
        s.erase(s.begin());
        s.insert(cur+a[i]);
    }
    return (*s.rbegin()<=t);
}

int main(){

    freopen("cowdance.out","w",stdout);
    freopen("cowdance.in","r",stdin);

    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    int l=0,r=n;
    while(r-l>1){
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
}