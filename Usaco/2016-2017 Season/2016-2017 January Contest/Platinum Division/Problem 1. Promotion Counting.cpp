//USACO 2017 January Contest, Platinum
//Problem 1. Promotion Counting
//merge sort tree
//dp with segment tree 
#include <bits/stdc++.h>
#define mid (l+r)/2
#define ri node+node+1
#define le node+node
#define ll long long
using namespace std;
const int inf=1e5+9;
int a[inf],n,in[inf],out[inf],timer,id[inf];
vector<int> tree[inf<<2],v[inf];

void dfs(int node,int par){

    id[timer]=node;
    in[node]=timer++;
    for(auto o:v[node])
        if(o!=par)
            dfs(o,node);

    out[node]=timer-1;
}

void build(int node,int l,int r){

    if(l==r)
        return void(tree[node].push_back( a[id[l]]  ));

    build(le,l,mid);
    build(ri,mid+1,r);

    int x=0,y=0;
    while(x<tree[le].size() && y<tree[ri].size())
        if(tree[le][x]>tree[ri][y])
            tree[node].push_back(tree[ri][y++]);
        else
            tree[node].push_back(tree[le][x++]);

    while(x<tree[le].size())
        tree[node].push_back(tree[le][x++]);

    while(y<tree[ri].size())
        tree[node].push_back(tree[ri][y++]);
}

int query(int node,int l,int r,int x,int y,int val){

    if(l>r || r<x || l>y)
        return 0;
    if(l>=x && r<=y)
        return tree[node].size()-(upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin());

    return query(le,l,mid,x,y,val)+query(ri,mid+1,r,x,y,val);
}

int main(){

    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);

    for(int i=2;i<=n;i++){
        int vertex;
        scanf("%d",&vertex);
        v[i].push_back(vertex);
        v[vertex].push_back(i);
    }
    dfs(1,0);

    build(1,1,n);

    for(int i=1;i<=n;i++)
        printf("%d\n",query(1,1,n,in[i],out[i],a[i]));

}