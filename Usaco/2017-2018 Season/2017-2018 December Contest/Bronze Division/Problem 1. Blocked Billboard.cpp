
//USACO 2017 December Contest, Bronze
//Problem 1. Blocked Billboard
#include <bits/stdc++.h>
using namespace std;

const int MX=1e9+9;

struct rec{
    int start_x,start_y,end_x,end_y;
};

rec inter(rec r1,rec r2){

if(r1.start_x==MX || r2.start_x == MX)
    return {MX,MX,MX,MX};

int leftX      =  max( r1.start_x, r2.start_x );
int rightX    = min( r1.end_x, r2.end_x );
int topY       = max( r1.start_y, r2.start_y );
int bottomY = min( r1.end_y, r2.end_y );

if ( leftX <= rightX && topY <= bottomY )
  return { leftX, topY, rightX, bottomY};

    return {MX,MX,MX,MX};
}

int main(){
	
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);

    rec a,b,c;
    cin>>a.start_x>>a.start_y>>a.end_x>>a.end_y;

    cin>>b.start_x>>b.start_y>>b.end_x>>b.end_y;

    cin>>c.start_x>>c.start_y>>c.end_x>>c.end_y;

    int ans=(a.end_x-a.start_x)*(a.end_y-a.start_y)+(b.end_x-b.start_x)*(b.end_y-b.start_y);

    rec temp=inter(a,c);

    if(temp.start_x<MX)
        ans-=(temp.end_x-temp.start_x)*(temp.end_y-temp.start_y);

    temp=inter(b,c);

      if(temp.start_x<MX)
        ans-=(temp.end_x-temp.start_x)*(temp.end_y-temp.start_y);

    cout<<ans<<endl;
}