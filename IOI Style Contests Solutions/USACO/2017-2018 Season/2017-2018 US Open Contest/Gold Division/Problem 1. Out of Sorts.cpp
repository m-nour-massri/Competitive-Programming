//USACO 2018 US Open Contest, Gold
//Problem 1. Out of Sorts
#include <bits/stdc++.h>
#define mid (l+r)/2
#define le node+node
#define ri le+1
using namespace std;
const int inf=1e5+9;
pair<int,int> a[inf];
int tree[inf<<2];

void update(int node,int l,int r,int idx){
    if(l==r){
        tree[node]=1;
        return ;
    }
    if(idx<=mid)
        update(le,l,mid,idx);
    else update(ri,mid+1,r,idx);
    tree[node]=tree[le]+tree[ri];
}

int query(int node,int l,int r,int x,int y){
    if(l>r || r<x || l>y)
        return 0;
    if(l>=x && r<=y)
        return tree[node];
    return query(le,l,mid,x,y)+query(ri,mid+1,r,x,y);
}

int main(){
   freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int   n,ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ans=max(ans,query(1,1,n,i,n));
        update(1,1,n,a[i].second);
    }
    cout<<ans<<endl;
}