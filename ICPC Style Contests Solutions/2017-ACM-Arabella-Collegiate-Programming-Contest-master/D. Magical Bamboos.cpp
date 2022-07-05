#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf];
void solve(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        if((a[i]-a[i-1])%2==1){
            printf("no\n");
            return ;
        }
    printf("yes\n");
    return;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
