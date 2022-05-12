//TOKI OSN Open Contest 2019 - Day 1
//1B. Manado Defense
#include <bits/stdc++.h>
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
#define ll long long
using namespace std;
const ll inf=2e5+9,MX=1e18+9;
ll n,m,price,tree[inf<<2],dp[inf];
vector<pair<ll,ll> > packets[inf];

ll query(ll node,ll l,ll r,ll x,ll y){
    if(y>n)
        return 0;
    if(l>r || r<x || l>y || x>y)
        return MX;
     if(l>=x && r<=y)
        return tree[node];
    return min( query(le,l,mid,x,y) , query(ri,mid+1,r,x,y) );
}

void update(ll node,ll l,ll r,ll idx,ll val){

    if(l == r)
        return void(tree[node] = val);
    if(idx<=mid)
        update(le,l,mid,idx,val);
    else
        update(ri,mid+1,r,idx,val);
    tree[node] = min(tree[le],tree[ri]);
}

int main(){

    cin>>n>>m>>price;
    for(ll i=1;i<=m;i++){
        ll x,y,z;
        cin>>x>>y>>z;
        packets[x].push_back(make_pair(y,z));
    }

    for(ll i=n;i>=1;i--){
        dp[i] = dp[i+1]+price;
        for(auto o:packets[i])
            dp[i] = min(dp[i] , o.second + query(1,1,n,i+1,o.first+1));
        update(1,1,n,i,dp[i]);
    }
    cout<<dp[1]<<endl;
}
