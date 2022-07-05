//USACO 2012 November Contest, Bronze
//Problem 2. Typo
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;

int n,ans,pre[inf],suf[inf],pre_ok[inf],suf_ok[inf];
string a;
int main(){

    freopen("typo.in","r",stdin);
    freopen("typo.out","w",stdout);

    cin>>a;
    a=" "+a;
    n=a.size()-1;
    pre_ok[0]=suf_ok[n+1]=1;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+(a[i]=='('?1:-1),pre_ok[i]=(pre_ok[i-1] & pre[i]>=0);

    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+(a[i]=='('?1:-1),suf_ok[i]=(suf_ok[i+1] & suf[i]<=0);

    for(int i=1;i<=n;i++){
        if(!pre_ok[i-1]  || !suf_ok[i+1])
            continue;
        if(a[i]=='(')
            ans+=(pre[i-1]>0 && pre[i-1]+suf[i+1]-1==0);
        else
            ans+=( pre[i-1]+suf[i+1]+1==0);
    }

    cout<<ans<<endl;
}