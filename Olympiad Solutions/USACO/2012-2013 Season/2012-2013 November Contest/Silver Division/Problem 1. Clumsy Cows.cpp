
//USACO 2012 November Contest, Silver
//Problem 1. Clumsy Cows
#include <bits/stdc++.h>
using namespace std;
string a;
int ans,n;
int main(){

    freopen("clumsy.in","r",stdin);
    freopen("clumsy.out","w",stdout);

    cin>>a;
    n=a.size();
    a=" "+a;
    int sum=0;
    for(int i=1;i<=n;i++){
        int val=(a[i]==')'?-1:1);
        if(sum+val<0)
            ans++,sum++,a[i]='(';
        else
            sum+=val;
    }
    sum=0;
    for(int i=n;i>=1;i--){
        int val=(a[i]=='('?-1:1);
        if(sum+val<0)
            ans++,sum++,a[i]=')';
        else
            sum+=val;
    }
    cout<<ans<<endl;
}