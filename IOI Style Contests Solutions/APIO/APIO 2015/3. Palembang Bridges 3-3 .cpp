
//APIO 2015 Palembang Bridges
//3-3 subtasks solution 9 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,ans,cnt,sum;
vector<pair<ll,ll> > v;
vector<ll> all;

ll go(ll pos1,ll pos2){
    ll ret=0;
    for(auto o:v)
        ret+=min(abs(o.first-pos1)+abs(o.second-pos1),abs(o.first-pos2)+abs(o.second-pos2));
    return ret;
}

int main(){

    cin>>k>>n;
    for(ll i=1;i<=n;i++){
        char x,y;
        ll a,b;
        cin>>x>>a>>y>>b;
        if(x==y)
            ans+=abs(a-b);
        else
            v.push_back(  x=='A'?make_pair(a,b):make_pair(b,a) ),sum+=a+b,cnt+=2,all.push_back(a),all.push_back(b);
    }
    if(cnt){
        ans+=cnt/2;
        ll temp=1e18+9;
        for(auto o:all)
            for(auto u:all)
                temp=min(temp,go(o,u));
        ans+=temp;
    }
    cout<<ans<<endl;
}