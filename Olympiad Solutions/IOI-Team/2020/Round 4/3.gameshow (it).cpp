
//IOI team 3.Pay That Box! (gameshow)
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5+9;
int n,k,a[inf],b[inf],ans;

int main(){

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++){
        if(k >= a[i])
            k-= a[i],ans++;
        else
            k += b[i];
    }
    cout<<ans<<" "<<k<<endl;
}