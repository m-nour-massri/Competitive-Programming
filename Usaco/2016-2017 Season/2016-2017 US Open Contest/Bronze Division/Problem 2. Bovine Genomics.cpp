//USACO 2017 US Open Contest, Bronze
//Problem 2. Bovine Genomics
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int n,m,ans;
string plain[inf],spotty[inf];

int main(){

    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>plain[i],plain[i] = " "+plain[i];

    for(int i=1;i<=n;i++)
        cin>>spotty[i],spotty[i] = " "+spotty[i];

    for(int i=1;i<=m;i++){
        set<int> s;
        bool tr=1;
        for(int j=1;j<=n;j++)
            s.insert(plain[j][i]);
        for(int j=1;j<=n;j++)
            if(s.count(spotty[j][i]))
                tr=0;
        ans+=tr;
    }
    cout<<ans<<endl;
}