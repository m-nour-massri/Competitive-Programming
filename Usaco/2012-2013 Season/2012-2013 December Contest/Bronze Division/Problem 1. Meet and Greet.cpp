//USACO 2012 December Contest, Bronze
//Problem 1. Meet and Greet
#include <bits/stdc++.h>
using namespace std;
const int inf=5e4+9;
int n,m,ans;
int a[inf],b[inf];
char dira[inf],dirb[inf];

int main(){

    freopen("greetings.in","r",stdin);
    freopen("greetings.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>dira[i],a[i]+=a[i-1];

    for(int i=1;i<=m;i++)
        cin>>b[i]>>dirb[i],b[i]+=b[i-1];

    int time=1,l=1,r=1,x=0,y=0;
    bool together=1;
    while(l<=n && r<=m){
        x+=(dira[l] == 'L'?-1:1);
        y+=(dirb[r] == 'L'?-1:1);
        if(x != y)
            together=0;
        ans+=(x==y && !together);
        if( x == y)
            together=1;
        time++;
        if(time>a[l])
            l++;
        if(time>b[r])
            r++;
    }

    while(l<=n){
        x+=(dira[l] == 'L'?-1:1);
        ans+=(x==y);
        time++;
        if(time>a[l])
            l++;
    }

    while(r<=m){
        y+=(dirb[r] == 'L'?-1:1);
        ans+=(x==y);
        time++;
        if(time>b[r])
            r++;
    }
    cout<<ans<<endl;
}