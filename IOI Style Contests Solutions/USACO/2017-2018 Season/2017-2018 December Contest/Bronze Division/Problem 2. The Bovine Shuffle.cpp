
//USACO 2017 December Contest, Bronze
//Problem 2. The Bovine Shuffle
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int n,a[inf],cur[inf],pos[inf];
int main(){

    freopen("shuffle.out","w",stdout);
    freopen("shuffle.in","r",stdin);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],pos[a[i]]=i;

    for(int i=1;i<=n;i++)
        cin>>cur[i];

    for(int j=1;j<=3;j++){

        int pre[inf]={0};
        for(int i=1;i<=n;i++)
            pre[pos[i]]=cur[i];

        for(int i=1;i<=n;i++)
            cur[i]=pre[i];
    }
    for(int i=1;i<=n;i++)
        cout<<cur[i]<<" ";
}