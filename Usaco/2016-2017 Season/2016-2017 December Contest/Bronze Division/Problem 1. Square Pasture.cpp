//USACO 2016 December Contest, Bronze
//Problem 1. Square Pasture
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("square.in","r",stdin);freopen("square.out","w",stdout);
    int x1,y1,x2,y2,te;
    cin>>x1>>y1>>x2>>y2;
    cin>>te;
    x1=min(x1,te);
    cin>>te;
    y1=min(y1,te);
    cin>>te;
    x2=max(x2,te);
    cin>>te;
    y2=max(y2,te);
    cout<<max(abs(x1-x2)*abs(x1-x2),abs(y1-y2)*abs(y1-y2))<<endl;
}
