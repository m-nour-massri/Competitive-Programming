//Problem B subtask 2
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const int inf=5e4+9;
int n,m,q;
int tree[inf<<2];

void update(int node,int l,int r,int idx,int val){

    if(l==r)
        return void(tree[node]=val);
    if(mid>=idx)
        update(le,l,mid,idx,val);
    else
        update(ri,mid+1,r,idx,val);
    tree[node]=min(tree[le],tree[ri]);
}

int query(int node,int l,int r,int x,int y){

    if(l>r || r< x || l>y )
        return 1e9+9;
    if(l>=x && r<=y)
        return tree[node];
    return min(query(le,l,mid,x,y),query(ri,mid+1,r,x,y));
}

int main(){

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        update(1,1,n-1,i,z);
    }
    cin>>q;
    while(q--){

        int type,a,b;
        cin>>type>>a>>b;
        if(type==1){
            update(1,1,n-1,a,b);
        }
        else {
            int l=a-1   ,r=n,ans=1;
            while(r-l>1){
                int mi= (l+r)/2;
                int s=query(1,1,n-1,a,mi);
                if(s>=b)
                    l=mi;
            else
                r=mi;
            }
            ans+=(l-a+1);
            //cout<<ans<<" ";
            l=0,r=a;
            while(r-l>1){
                int mi=(l+r)/2;
                int s=query(1,1,n-1,mi,a-1);
                if(s>=b)
                    r=mi;
                else
                    l=mi;
            }
            ans+=(a-r);
            cout<<ans<<endl;
        }
    }
}
