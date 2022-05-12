//USACO 2016 December Contest, Silver
//Problem 3. Moocast
#include <bits/stdc++.h>
using namespace std;
const int inf=2e2+9;
pair<pair<long long ,long long >,long long > a[inf];
bool vis[inf];
long long  n;

long long  dis(long long  x,long long  y){
    return abs(a[x].first.first-a[y].first.first)*abs(a[x].first.first-a[y].first.first)+
    abs(a[x].first.second-a[y].first.second)*abs(a[x].first.second-a[y].first.second);
}

void dfs(long long  pos){
    vis[pos]=1;

    for(long long  i=1;i<=n;i++){
        if(i==pos)
            continue;
        if(a[pos].second*a[pos].second>=dis(i,pos) && !vis[i])
            dfs(i);
    }
}
int  main(){
    freopen("moocast.out","w",stdout);freopen("moocast.in","r",stdin);
    cin>>n;
    for(long long  i=1;i<=n;i++)
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;

    long long  ans=0;
    for(long long  i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs(i);
        long long  te=0;
        for(long long  i=1;i<=n;i++)
            te+=vis[i];
        ans=max(ans,te);
    }
    cout<<ans<<endl;
}
