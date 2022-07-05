//USACO 2014 December Contest, Gold
//Problem 2. Marathon
#include <bits/stdc++.h>
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
#define ll long long
using namespace std;
const ll inf=1e5+9,MX=1e18+9;
ll x[inf],y[inf],pre[inf],suf[inf],rem[inf],tree[inf<<2],lazy[inf<<2], par[inf<<2][2];


ll dis(ll i,ll j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

void build(ll node,ll l,ll r){

    if(l==r)
        return void(tree[node]=rem[l]);

    build(le,l,mid);
    build(ri,mid+1,r);
    tree[node]=min(tree[le],tree[ri]);

}

void L(ll node,ll l,ll r){

    if(lazy[node]==0)
        return ;

    tree[node]+=lazy[node];
    if(l!=r)
        lazy[le]+=lazy[node],lazy[ri]+=lazy[node];
    lazy[node]=0;

}

void update(ll node,ll l,ll r,ll x,ll y,ll val){

    L(node,l,r);

    if(l>r || r<x || l>y)
        return ;

    if(l>=x && r<=y){
        lazy[node]+=val;
        L(node,l,r);
        return ;
    }

    update(le,l,mid,x,y,val);
    update(ri,mid+1,r,x,y,val);
    tree[node]=min(tree[le],tree[ri]);
}

ll query(ll node,ll l,ll r,ll x,ll y){

    L(node,l,r);
    if(l>r || r<x || l>y)
        return MX;

    if(l>=x && r<=y)
        return tree[node];

    ll s=min(query(le,l,mid,x,y),query(ri,mid+1,r,x,y));
    tree[node]=min(tree[le],tree[ri]);
    return s;
}


void UP(ll node,ll l,ll r,ll x,ll y,ll val,bool is){

    if(x>y || l>r || l>y || r<x)
        return ;
    if(l>=x && r<=y)
        return void(par[node][is]+=val);
    if(x<=mid)
        UP(le,l,mid,x,y,val,is);
    if(y>mid)
        UP(ri,mid+1,r,x,y,val,is);

}

ll Q(ll node,ll l,ll r,ll idx,bool is){

    if(l==r)
        return par[node][is];

    if(idx<=mid)
        return par[node][is]+Q(le,l,mid,idx,is);
    else
        return par[node][is]+Q(ri,mid+1,r,idx,is);
}

int main(){

    freopen("marathon.out","w",stdout);
    freopen("marathon.in","r",stdin);

    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>x[i]>>y[i];

    for(ll i=1;i<=n;i++)
        pre[i]=pre[i-1]+dis(i-1,i),UP(1,1,n,i,i,pre[i],0);

    for(ll i=n;i>=1;i--)
        suf[i]=suf[i+1]+dis(i+1,i),UP(1,1,n,i,i,suf[i],1);

    for(ll i=1;i<=n;i++)
        rem[i]=pre[i-1]+suf[i+1]+dis(i-1,i+1);

    build(1,1,n);
    while(q--){
        char ty;
        ll l,r,p;
        cin>>ty;
        if(ty=='U'){
            cin>>p>>l>>r;
            ll add;
            x[n+2]=l,y[n+2]=r;

            add=dis(p-1,n+2)+dis(p+1,n+2)-dis(p-1,p)-dis(p+1,p);

            update(1,1,n,p+2,n-1,add);
            update(1,1,n,2,p-2,add);

            add=dis(p-1,n+2)-dis(p-1,p)+dis(n+2,p+2)-dis(p,p+2);
            update(1,1,n,p+1,p+1,add);

            add=dis(p+1,n+2)-dis(p+1,p);
            add+=dis(n+2,p-2)-dis(p,p-2);
            update(1,1,n,p-1,p-1,add);


                UP(1,1,n,p,p,dis(n+2,p-1)-dis(p,p-1),0);

                UP(1,1,n,p,p,dis(n+2,p+1)-dis(p,p+1),1);

                UP(1,1,n,p+1,n,dis(n+2,p+1)+dis(n+2,p-1)-dis(p,p+1)-dis(p,p-1),0);

                UP(1,1,n,1,p-1,dis(n+2,p+1)+dis(n+2,p-1)-dis(p,p+1)-dis(p,p-1),1);

            x[p]=l,y[p]=r;

        }
        else
            cin>>l>>r,cout<<query(1,1,n,l+1,r-1)-Q(1,1,n,l,0)-Q(1,1,n,r,1)<<endl;
    }
}