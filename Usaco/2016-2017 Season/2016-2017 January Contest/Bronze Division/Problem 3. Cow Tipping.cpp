
//USACO 2017 January Contest, Bronze
//Problem 3. Cow Tipping
#include <bits/stdc++.h>
using namespace std;
const int inf=13;
int n,ans;
int a[inf][inf];

int main(){

    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=1;j<=n;j++)
            a[i][j] = tmp[j-1] == '1';
    }

    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(a[i][j] == 1){
                ans++;
                for(int x=1;x<=i;x++)
                    for(int y=1;y<=j;y++)
                        a[x][y] = (a[x][y]==0?1:0);
            }
        }
    }
    cout<<ans<<endl;
}