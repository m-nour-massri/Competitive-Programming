//USACO 2017 US Open Contest, Silver
//Problem 2. Bovine Genomics
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 509 , base = 5 ,mod = 1e15+7;

ll n,m,ans ,cnt;
ll hash1[inf],hash2[inf],mul[inf];
ll spotty[inf][inf] , plain[inf][inf];
map<char,ll> mp;
int store[inf+inf];

int main(){

    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    mp['A'] = 1,mp['T'] = 2,mp['C']=3,mp['G']=4;

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(ll j=1;j<=m;j++)
            spotty[i][j] = mp[ tmp[j-1] ] ;
    }

    for(ll i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(ll j=1;j<=m;j++)
            plain[i][j] = mp[ tmp[j-1] ] ;
    }
    mul[0] = 1;
    for(ll i=1;i<=m;i++)
       mul[i] = (mul[i-1] * base)%mod; // (base^i)%mod or we can set it to rand()%mod

    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            for(int z=j+1;z<=m;z++){
                set<int> s;
                bool tr=1;
                cnt++;
                for(int k=1;k<=n;k++)
                    store[ spotty[k][i]*mul[1] + spotty[k][j]*mul[2] + spotty[k][z]*mul[3] ] = cnt ;
                 for(int k=1;k<=n;k++)
                    if( store[plain[k][i]*mul[1] + plain[k][j]*mul[2] + plain[k][z]*mul[3] ] == cnt )
                        tr=0;
                ans+=tr;
            }
    cout<<ans<<endl;
}