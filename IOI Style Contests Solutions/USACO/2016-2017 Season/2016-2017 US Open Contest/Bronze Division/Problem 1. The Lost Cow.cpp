//USACO 2017 US Open Contest, Bronze
//Problem 1. The Lost Cow
#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);

    int x,y,ans=0,d=1,pos;
    cin>>x>>y;
    pos = x;
    while(1){
        while(x<pos+d){
            x++;
            ans++;
            if( x == y )
                cout<<ans<<endl,exit(0);
        }
        while(x>pos+d){
            x--;
            ans++;
            if( x == y)
                cout<<ans<<endl,exit(0);
        }
        d*=-2;
    }
}