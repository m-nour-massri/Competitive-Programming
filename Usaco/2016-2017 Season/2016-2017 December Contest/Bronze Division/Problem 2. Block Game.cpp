
//USACO 2016 December Contest, Bronze
//Problem 2. Block Game
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
string a[inf],b[inf];
int ans[inf];
int main(){

    freopen("blocks.in","r",stdin);freopen("blocks.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];

    for(char i='a';i<='z';i++){
            int sum=0;
        for(int j=1;j<=n;j++){
            int te=0,mx=0;
            for(int z=0;z<a[j].size();z++)
                if(a[j][z]==i)
                    te++;
            mx=te;
            te=0;
            for(int z=0;z<b[j].size();z++)
                if(b[j][z]==i)
                    te++;
            mx=max(mx,te);
        sum+=mx;
        }
        ans[i-'a']=sum;
    }
    for(int i=0;i<26;i++)
        cout<<ans[i]<<endl;
}