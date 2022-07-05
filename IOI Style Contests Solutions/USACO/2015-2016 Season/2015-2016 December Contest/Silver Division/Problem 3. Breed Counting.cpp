//USACO 2015 December Contest, Silver
//Problem 3. Breed Counting
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf],par[inf][5];
int main(){
    freopen("bcount.out","w",stdout);
    freopen("bcount.in","r",stdin);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        par[i][1]=par[i-1][1]+(a[i]==1),
        par[i][2]=par[i-1][2]+(a[i]==2),
        par[i][3]=par[i-1][3]+(a[i]==3);

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<par[r][1]-par[l-1][1]<<" "<<par[r][2]-par[l-1][2]<<" "<<par[r][3]-par[l-1][3]<<"\n";
    }
}