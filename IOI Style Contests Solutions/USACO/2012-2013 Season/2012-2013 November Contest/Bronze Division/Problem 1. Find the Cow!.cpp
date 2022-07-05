
//USACO 2012 November Contest, Bronze
//Problem 1. Find the Cow!
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,cnt;
int main(){

    freopen("cowfind.in","r",stdin);
    freopen("cowfind.out","w",stdout);

    string a;
    cin>>a;
    for(int i=0;i<a.size()-1;i++)
        ans+=(a[i]==a[i+1] && a[i]==')')*cnt,
        cnt+=(a[i]==a[i+1] && a[i]=='(');

    cout<<ans<<endl;
}