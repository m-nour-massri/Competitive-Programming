//USACO 2016 January Contest, Bronze
//Problem 2. Angry Cows
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
bool vis[inf];
int n,a[inf];

int check(int x){
    int cur=0;
    queue<pair<int,int> > q;
    memset(vis,0,sizeof(vis));

    q.push(make_pair(x,1));
    while(!q.empty()){

        pair<int,int> p=q.front();
        q.pop();
        int node=p.first;
        if(vis[node])
            continue;
            cur++;
        vis[node]=1;
        for(int i=1;i<=n;i++)
            if(abs(a[node]-a[i])<=p.second )
                q.push(make_pair(i,p.second+1));
    }
    return cur;
}
int main(){

    freopen("angry.out","w",stdout);
    freopen("angry.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,check(i));

    cout<<ans<<endl;
}