//USACO 2016 December Contest, Bronze
//Problem 3. The Cow-Signal
#include <bits/stdc++.h>
using namespace std;
string a[44],ans[33];
int main(){
    freopen("cowsignal.in","r",stdin);freopen("cowsignal.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans[i]="";
        for(int j=0;j<a[i].size();j++)
            for(int z=0;z<k;z++)
                ans[i]+=a[i][j];
    }
    for(int i=0;i<n;i++)
        for(int z=0;z<k;z++)
            cout<<ans[i]<<endl;

}
