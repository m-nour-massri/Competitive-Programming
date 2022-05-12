
//USACO 2018 December Contest, Silver
//Problem 1. Convention
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const long long  inf=1e5+9;
long long  a[inf];
long long  n,m,c;

bool check(long long  x){

    long long  st=1;
    long long  rem=m;
    for(long long  i=2;i<=n;i++){
        if(a[i]-a[st]>x || i-st+1>c)
            st=i,rem--;
        if(rem<=0)
            return 0;
    }
    return 1;
}

int  main(){

    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);

    cin>>n>>m>>c;
    for(long long  i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);

    long long  l=0,r=1e9+9;
    while(r-l>1){
        if(check(mid))
            r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
