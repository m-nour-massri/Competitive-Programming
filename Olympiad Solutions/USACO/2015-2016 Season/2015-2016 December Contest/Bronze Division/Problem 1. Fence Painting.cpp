//USACO 2015 December Contest, Bronze
//Problem 1. Fence Painting
#include <bits/stdc++.h>
using namespace std;
const int MX=1e9+9;
struct seg{
    int x,y;
};

seg inter(seg r1,seg r2){

if(r1.x==MX || r2.x == MX)
    return {MX,MX};

int left      =  max( r1.x, r2.x );
int right    = min( r1.y, r2.y );

if ( left <= right )
  return { left, right};

    return {MX,MX};
}

int main(){
    freopen("paint.out","w",stdout);
    freopen("paint.in","r",stdin);
    seg a,b,in;
    cin>>a.x>>a.y>>b.x>>b.y;
    in=inter(a,b);
    if(in.x==MX)
        cout<<a.y-a.x+b.y-b.x<<endl;
    else cout<<a.y-a.x+b.y-b.x-in.y+in.x<<endl;
}