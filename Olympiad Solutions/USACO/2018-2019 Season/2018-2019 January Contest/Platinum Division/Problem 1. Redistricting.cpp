//USACO 2019 January Contest, Platinum
//Problem 1. Redistricting
//dp with segment tree
#include <bits/stdc++.h>
#define mid (l+r)/2
#define ri node+node+1
#define le node+node
using namespace std;
const int inf=3e5+9,MX=1e9+7;
int dp[inf],par[inf],cnt,tree[inf<<2],n,k;
map<int,int> mp;
multiset<int> s[inf<<2];
string ss;

void update(int node,int l,int r,int idx,int val)
{

    if(l==r)
    {
        s[node].insert(val);
        tree[node]=*s[node].begin();
        return ;
    }

    if(idx<=mid)
        update(le,l,mid,idx,val);
    else update(ri,mid+1,r,idx,val);
    tree[node]=min(tree[le],tree[ri]);
}

void del(int node,int l,int r,int idx,int val)
{

    if(l==r)
    {
        s[node].erase(s[node].find(val));
        if(s[node].empty())
            tree[node]=MX;
        else tree[node]=*s[node].begin();
        return ;
    }
    if(idx<=mid)
        del(le,l,mid,idx,val);
    else del(ri,mid+1,r,idx,val);
    tree[node]=min(tree[le],tree[ri]);
}

int query(int node,int l,int r,int x,int y)
{
    if(x>y)
        return MX;
    if(l>=x && r<=y)
        return tree[node];

    int d=MX,f=MX;
    if(x<=mid)
        d=query(le,l,mid,x,y);
    if(y>mid)
        f=query(ri,mid+1,r,x,y);
    return min(d,f);
}
char fi[inf];
int main()
{
    freopen("redistricting.out","w",stdout);
    freopen("redistricting.in","r",stdin);

    scanf("%d%d",&n,&k);
    scanf("%s",fi);
    ss=(string)fi;
    ss=" "+ss;
    for(int i=1; i<=n; i++)
        par[i]=par[i-1]+(ss[i]=='G'?-1:1),mp[par[i]];

    mp[0];

    for(auto &o:mp)
        o.second=++cnt;

    memset(tree,21,sizeof(tree));
    update(1,1,cnt,mp[0],0);

    for(int i=1; i<=n; i++)
    {

        if(i-k-1>=0)
            del(1,1,cnt,mp[par[i-k-1]],dp[i-k-1]);


        dp[i]=min(   query(1,1,cnt,1,mp[par[i]]-1),
                     query(1,1,cnt,mp[par[i]],cnt)+1);

        update(1,1,cnt,mp[par[i]],dp[i]);

    }
    /*
    //slow dp
    for(int i=1; i<=n; i++){
        int cur=0;
        dp[i]=MX;
        for(int j=i; j>=max(1,i-k+1); j--){
            cur+=(ss[j]=='G');
            bool x=(cur>=i-j+1-cur);
            dp[i]=min(dp[i],x+dp[j-1]);
        }
        cout<<dp[i]<<" ";
    }*/

    printf("%d\n",dp[n]);
}
