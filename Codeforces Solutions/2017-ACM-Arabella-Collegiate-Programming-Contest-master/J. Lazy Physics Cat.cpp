#include <bits/stdc++.h>
using namespace std;

void solve(){
    long double l,a;
    cin>>l>>a;
    long double area=l*l*a/(long double)360.0;
    area*=acos(-1);
    long double f=sin(a);
    long double s=(long double)l*l*sin(a * (acos(-1) / 180.0))/(long double)2.0;
    area-=s;
    cout<<fixed<<setprecision(6)<<area<<endl;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}