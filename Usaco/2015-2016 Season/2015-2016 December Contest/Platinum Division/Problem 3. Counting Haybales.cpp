
#include <bits/stdc++.h>
#define ll long long
#define ri node+node+1
#define le node+node
#define mid (l+r)/2
using namespace std;
const ll inf=2e5+9,MX=1e9+9;
ll a[inf],n,q,lazy[inf<<2];
pair<ll,ll> tree[inf<<2];

void build(ll node,ll l,ll r){

    if(l==r)
        return void(tree[node]=make_pair(a[l],a[l]));
    build(le,l,mid);
    build(ri,mid+1,r);
    tree[node]=make_pair(tree[le].first+tree[ri].first,min(tree[le].second,tree[ri].second));
}

void L(ll node,ll l,ll r){

    tree[node].first+=(r-l+1)*lazy[node];
    tree[node].second+=lazy[node];
    if(l!=r)
        lazy[le]+=lazy[node],lazy[ri]+=lazy[node];
    lazy[node]=0;
}

void update(ll node,ll l,ll r,ll x,ll y,ll val){

    L(node,l,r);
    if(l>r || r<x || l>y)
        return ;

    if(l>=x && r<=y){
        lazy[node]=val;
        L(node,l,r);
        return ;
    }
    update(le,l,mid,x,y,val);
    update(ri,mid+1,r,x,y,val);
    tree[node]=make_pair(tree[le].first+tree[ri].first,min(tree[le].second,tree[ri].second));

}

pair<ll,ll> query(ll node,ll l,ll r,ll x,ll y){

    L(node,l,r);
    if(l>r || r<x || l>y)
        return make_pair(0,MX);

    if(l>=x && r<=y)
        return tree[node];

    pair<ll,ll> d=query(le,l,mid,x,y),f=query(ri,mid+1,r,x,y);
    tree[node]=make_pair(tree[le].first+tree[ri].first,min(tree[le].second,tree[ri].second));
    return make_pair(d.first+f.first,min(d.second,f.second));
}

int main(){
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;++i)
        cin>>a[i];

    build(1,1,n);
    while(q--){
        char ty;
        ll l,r,val;
        cin>>ty>>l>>r;

        if(ty=='M')
            cout<<query(1,1,n,l,r).second<<endl;
        else if(ty=='S')
            cout<<query(1,1,n,l,r).first<<endl;
        else
            cin>>val,update(1,1,n,l,r,val);
    }

}
