
//hacker earth Easy Queries
//Tags: Segment tree - Binary search - Data structures 
#include <bits/stdc++.h>
#define mid (l+r)/2
#define le node+node
#define ri le+1
using namespace std;
const int inf=1e5+9;
int a[inf],tree[inf<<2];

void update(int node,int l,int r,int idx,int val){
    if(l==r){
        tree[node]=val;
        return ;
    }
    if(idx<=mid)
        update(le,l,mid,idx,val);
    else update(ri,mid+1,r,idx,val);
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

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],update(1,1,n,i,a[i]);

    while(q--){
        int ty,x;
        cin>>ty>>x;
        x++;
        if(ty==1){
            update(1,1,n,x,1);
            continue;
        }
        bool is=0;
        int k=query(1,1,n,1,x);
        if(query(1,1,n,1,x-1)==k-1){
            is=1;
            update(1,1,n,x,0);
            k--;
        }
        int d,f;
        int l=x-1,r=n+1;
        while(r-l>1){
            if(query(1,1,n,1,mid)>k)
                r=mid;
            else l=mid;
        }
        if(query(1,1,n,x,n)==0)
            r=0;
        f=r;
        l=0,r=x+1;
        while(r-l>1){
            if(query(1,1,n,1,mid)<k)
                l=mid;
            else r=mid;
        }
        if(query(1,1,n,1,x)==0)
            r=0;
        d=r;
        if(is)
            update(1,1,n,x,1);
        cout<<d-1<<" "<<f-1<<endl;
    }
}
