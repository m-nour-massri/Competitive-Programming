
//APIO 2015 Palembang Bridges
//1-1 subtasks solution 8 points
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,ans,cnt,sum;
vector<pair<ll,ll> > v;

ll go(ll pos){
    ll ret=0;
    for(auto o:v)
        ret+=abs(o.first-pos)+abs(o.second-pos)+1;
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
            v.push_back(  x=='A'?make_pair(a,b):make_pair(b,a) ),sum+=a+b,cnt+=2;
    }
    if(cnt){
        ll temp=0;
        sum/=cnt,
        temp=min(go(sum),min(go(sum+1),go(sum-1)));
        for(auto o:v)
            temp=min(temp,min(go(o.second),go(o.first)));
        ans+=temp;
    }
    //cout<<sum<<" "<<go(sum)<<" "<<go(sum+1)<<" "<<go(sum-1)<<endl;
    cout<<ans<<endl;
}