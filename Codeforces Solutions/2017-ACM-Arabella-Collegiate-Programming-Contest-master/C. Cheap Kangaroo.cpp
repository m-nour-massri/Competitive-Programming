#include <bits/stdc++.h>
using namespace std;
void solve(){

    long long n,gc, sum,x;
    scanf("%I64d%I64d",&n,&x);
    sum=gc=x;
    for(int i=2;i<=n;i++)
        scanf("%I64d",&x),sum+=x,gc=__gcd(gc,x);

    printf("%I64d %I64d\n",sum,gc);
}
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}