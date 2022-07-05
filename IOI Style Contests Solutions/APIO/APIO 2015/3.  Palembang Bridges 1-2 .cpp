//APIO 2015 Palembang Bridges
//1-2 subtasks solution 22 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,ans,cnt,sum2;
vector<ll> v;

int main(){

    cin>>k>>n;
    for(ll i=1;i<=n;i++){
        char x,y;
        ll a,b;
        cin>>x>>a>>y>>b;
        if(x==y)
            ans+=abs(a-b);
        else
            v.push_back(a),v.push_back(b),cnt+=2,sum2+=a+b;
    }
    ans+=cnt/2;
    if(cnt){
        ll temp=1e18+9;
        sort(v.begin(),v.end());
        ll sum1=0,sz=v.size();
        for(ll i=0;i<v.size();i++)
            sum1+=v[i],sum2-=v[i],temp=min(temp,(ll)(i+1ll)*v[i]-sum1 + sum2-(sz-i-1ll)*v[i] );
        ans+=temp;
    }
    cout<<ans<<endl;
}