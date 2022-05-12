//USACO 2015 December Contest, Bronze
//Problem 3. Contaminated Milk
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
vector<pair<long long ,long long > > v[inf];
pair<long long ,long long >si[inf];
int main(){

    freopen("badmilk.out","w",stdout);
    freopen("badmilk.in","r",stdin);

    long long n,m,d,s,rem;
    cin>>n>>m>>d>>s;
    rem=(1ll<<(m+1ll));
    rem--;
    for(long long  i=1;i<=d;i++){
        long long  a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    for(long long  i=1;i<=s;i++){
        long long  a,b;
        cin>>a>>b;
        si[i]=make_pair(a,b);
        for(auto o:v[a])
            if(o.second>=b && ((rem&(1ll<<o.first))!=0)  ){
                rem^=(1ll<<o.first);
            }
    }

    for(long long  i=1;i<=s;i++){
        long long mask=0;
        for(auto o:v[si[i].first])
            if(o.second<si[i].second)
                mask|=(1ll<<o.first);
        rem&=mask;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        long long te=0;
        for(auto o:v[i])
            te|=((rem&(1ll<<o.first))!=0);
        ans+=te;
    }
    cout<<ans<<endl;
}