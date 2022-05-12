
//USACO 2018 December Contest, Gold
//Problem 2. Cowpatibility
#include <bits/stdc++.h>
using namespace std;

const long long  inf=5e4+9,base=1e6+7,mod=1e12+11;
unordered_map<long long  ,long long > mp;
vector<long long  > v [inf];

long long hash1(vector<long long > x){

    long long ans=0;
    for(long long  i=0;i<x.size();i++)
        ans=((ans*base)%mod+x[i])%mod;
    return ans;
}

int main(){
    freopen("cowpatibility.in","r",stdin);
    freopen("cowpatibility.out","w",stdout);
    long long ans=0;
    long long  n;
    cin>>n;
    for(long long  i=1;i<=n;i++){
        for(long long  j=1;j<=5;j++){
            long long  x;
            cin>>x;
            v[i].push_back(x);
        }

        vector<long long   > mem;
        sort(v[i].begin(),v[i].end());

        for(long long   mask=1;mask<(1<<5);mask++){
            vector<long long  > te;

            for(long long  j=0;j<5;j++){
                if( (mask&(1<<j))==0 )
                    continue;
                te.push_back(v[i][j]);
            }
            long long tt=hash1(te);
            mem.push_back(tt);
            if(te.size()%2==1)
                ans+=mp[tt];
            else ans-=mp[tt];
        }
        for(auto o:mem)
            mp[o]++;

    }
    long long te=n*(n-1ll);
    te/=2ll;
    cout<<te-ans<<endl;
}