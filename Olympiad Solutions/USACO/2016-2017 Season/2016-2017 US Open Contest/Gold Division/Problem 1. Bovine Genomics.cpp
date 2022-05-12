
//USACO 2017 US Open Contest, Gold
//Problem 1. Bovine Genomics
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 509 , base = 5 ,mod = 1e15+7;

ll n,m,ans = mod;
ll hash1[inf],hash2[inf],mul[inf];
ll spotty[inf][inf] , plain[inf][inf];
map<char,ll> mp;

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

    ll r = 0,tr=0;
    for(ll i=1;i<=m;i++){
        while( r+1 <=m && !tr){
            r++;
            bool crash = 0;
            set<ll> s;
            for(ll j=1;j<=n;j++)
                hash1[j] = hash1[j] + mul[r] * spotty[j][r],hash1[j] %= mod,s.insert(hash1[j]);

            for(ll j=1; j<=n;j++)
                hash2[j] = hash2[j] + mul[r] *plain[j][r],hash2[j] %= mod,crash |= s.count( hash2[j] );
            if( !crash )
                tr = 1;
        }
        if(tr)
            ans = min(ans , r - i+1);

        bool crash = 0;
        set<ll> s;
        for(ll j=1;j<=n;j++)
            hash1[j] = mod+ hash1[j] - mul[i] * spotty[j][i],hash1[j] %= mod,s.insert(hash1[j]);

        for(ll j=1; j<=n;j++)
            hash2[j] = mod + hash2[j] - mul[i] *plain[j][i],hash2[j] %= mod,crash |= s.count( hash2[j] );
        if( crash )
            tr = 0;
    }
    cout<<ans<<endl;
}