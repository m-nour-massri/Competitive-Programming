//USACO 2016 January Contest, Bronze
//Problem 1. Promotion Counting
#include <bits/stdc++.h>
using namespace std;
int a[5],b[5];
int main(){

    freopen("promote.out","w",stdout);
    freopen("promote.in","r",stdin);

    int x,y,z;
    for(int i=0;i<4;i++)
        cin>>a[i]>>b[i];

    z=b[3]-a[3];

    y=z+b[2]-a[2];

    x=y+b[1]-a[1];

    cout<<x<<"\n"<<y<<"\n"<<z<<endl;
}