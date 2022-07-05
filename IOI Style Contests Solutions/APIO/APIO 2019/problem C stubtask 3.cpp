
//problem C stubtask 3
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const ll inf=3e5+9;
int n,q;
int tree[inf<<2];
string state;

void update(int node,int l,int r,int idx,int val){

    if(l==r)
        return void(tree[node]=val);

    if(idx<=mid)
        update(le,l,mid,idx,val);
    else
        update(ri,mid+1,r,idx,val);
    tree[node]=max(tree[le],tree[ri]);
}

int query(int node,int l,int r,int x,int y){

    if(l>r || r<x || l>y)
        return 0;
    if(l>=x && r<=y)
        return tree[node];
    return max(query(le,l,mid,x,y),query(ri,mid+1,r,x,y));
}

int main(){

    cin>>n>>q>>state;
    state=" "+state;
    for(int i=1;i<=n;i++)
       if(state[i]=='1')
            update(1,1,n,i,1);
    else
        update(1,1,n,i,1e9+9);

    for(int i=1;i<=q;i++){
        string type;
        int x,y;
        cin>>type>>x;
        if(type=="toggle")
            update(1,1,n,x,i+1);
        else
            cin>>y,cout<<max(i-query(1,1,n,x,y-1)+1,0)<<endl;
    }
}
