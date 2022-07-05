
//USACO 2018 December Contest, Bronze
//Problem 1. Mixing Milk
#include <bits/stdc++.h>
using namespace std;

    int c1,c2,c3,a,b,c,na,nb,nc;
int main(){
    freopen("mixmilk.out","w",stdout);
    freopen("mixmilk.in","r",stdin);
    cin>>c1>>a>>c2>>b>>c3>>c;
    for(int i=1;i<=100;i++){
        na=a,nb=b,nc=c;
        if(i%3==1){
            nb+=min(c2-b,a);
            na-=min(c2-b,a);
        }
        else if(i%3==2){
            nc+=min(c3-c,b);
            nb-=min(c3-c,b);
        }
        else {
            na+=min(c1-a,c);
            nc-=min(c1-a,c);
        }
        a=na,b=nb,c=nc;
    }
    cout<<a<<"\n"<<b<<"\n"<<c<<endl;
}