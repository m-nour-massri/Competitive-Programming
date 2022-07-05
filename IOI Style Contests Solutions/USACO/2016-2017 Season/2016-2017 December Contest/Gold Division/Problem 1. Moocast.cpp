
//USACO 2016 December Contest, Gold
//Problem 1. Moocast
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int inf=1e3+9;
long long  x[inf],y[inf],n;
bool vis[inf];
long long  dis(long long  i,long long  j){
    return abs(x[i]-x[j])*abs(x[i]-x[j])+abs(y[i]-y[j])*abs(y[i]-y[j]);
}

void dfs(long long  node,long long  co){
    vis[node]=1;
    for(long long  i=1;i<=n;i++)
        if(dis(i,node)<=co && !vis[i])
            dfs(i,co);

}

bool check(long long  x){
    memset(vis,0,sizeof(vis));
    dfs(1,x);
    long long  te=0;
    for(long long  i=1;i<=n;i++)
        te+=vis[i];

    return (te==n);
}

int main(){
    freopen("moocast.out","w",stdout);freopen("moocast.in","r",stdin);
    cin>>n;
    for(long long  i=1;i<=n;i++)
        cin>>x[i]>>y[i];

    long long  ans=0;
    long long  l=0,r=1e9+9;
    while(r-l>1){

        if(check(mid))
            r=mid;
        else l=mid;
    }

    cout<<r<<endl;
}


