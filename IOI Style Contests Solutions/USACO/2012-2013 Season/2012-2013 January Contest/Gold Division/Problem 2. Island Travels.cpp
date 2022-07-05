//USACO 2013 January Contest, Gold
//Problem 2. Island Travels
#include <bits/stdc++.h>
using namespace std;
const int inf=55,I=16,MX=1e9+9;
int n,m,NodeCnt,IslandCnt,ans=MX;
int node[inf][inf],dis[inf*inf][inf*inf],dp[I][(1<<I)+9];
string a[inf];
int idx[]={0,0,-1,1};
int idy[]={-1,1,0,0};
bool vis[inf][inf];
set <pair<int,int> > adj[inf*inf];

bool valid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=m ;
}

void dfs(int i,int j,int cur){

    vis[i][j]=1;
    node[i][j]=cur;
    for(int z=0;z<4;z++){
        int x=idx[z]+i,y=idy[z]+j;
        if(valid(x,y) && a[x][y]=='X' && !vis[x][y])
            dfs(x,y,cur);
    }
}

int solve(int cnt,int cur,int mask){

    if(cnt==IslandCnt)
        return 0;

    int &ret=dp[cur-1][mask>>1];
    if(ret!=-1)
        return ret;
    ret=MX;
    for(int i=1;i<=IslandCnt;i++)
        if( (mask&(1<<i))==0 )
            ret=min(ret,dis[cur][i]+solve(cnt+1,i,mask|(1<<i)));
    return ret;
}

int main(){

    freopen("island.in","r",stdin);
    freopen("island.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=" "+a[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[i][j] && a[i][j]=='X')
                dfs(i,j,++NodeCnt);

    IslandCnt=NodeCnt;
    //node->swim cost=0
    //swim->node cost=1
    //swim->swim cost=1
    memset(dis,21,sizeof(dis));//large value


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='S')
                continue;
            node[i][j]=++NodeCnt;
            for(int z=0;z<4;z++){
                int x=idx[z]+i,y=idy[z]+j;
                if(valid(x,y) && node[x][y])
                    adj[node[x][y]].insert(make_pair(NodeCnt, (node[x][y]>IslandCnt) )  ),
                    adj[NodeCnt].insert( make_pair(node[x][y],1)  );
            }
        }
    }

    for(int i=1;i<=NodeCnt;i++){

        dis[i][i]=0;
        deque<int> q;
        q.push_front(i);
        bool vis[inf*inf]={0};
        while(!q.empty()){
            int u=q.front();
            q.pop_front();
            if(vis[u])
                continue;
            vis[u]=1;
            for(auto v:adj[u]){
                if(dis[i][v.first]<=dis[i][u]+v.second)
                    continue;
                dis[i][v.first]=dis[i][u]+v.second;
                if(v.second==0)
                    q.push_front(v.first);
                else
                    q.push_back(v.first);
            }
        }
    }

    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=IslandCnt;i++)
        ans=min(ans,solve(1,i,(1<<i)));
    cout<<ans<<endl;
}