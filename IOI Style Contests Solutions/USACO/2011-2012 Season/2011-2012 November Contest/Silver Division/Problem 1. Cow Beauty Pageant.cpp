

//USACO 2011 November Contest Silver
//Problem 1. Cow Beauty Pageant
#include <bits/stdc++.h>
using namespace std;
const int inf=55;
bool vis[inf][inf];
string a[inf];
vector<pair<int,int> > v[55];
int idx[]={0,0,-1,1},idy[]={1,-1,0,0},n,m,cnt,ans=1e9+9;
void dfs(int i,int j){
    vis[i][j]=1;
    v[cnt].push_back(make_pair(i,j));
    for(int z=0;z<4;z++){
        int x=i+idx[z];
        int y=j+idy[z];
        if(x>=1 && y>=1 && x<=n && y<=m && !vis[x][y] && a[x][y]=='X')
            dfs(x,y);
    }
}

int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2)-1;
}

int bfs(int s,int d){
    int mn=1e9+9;
    for(auto o:v[s])
        for(auto u:v[d])
            mn=min(mn,dis(u.first,u.second,o.first,o.second));

    return mn;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=" "+a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='X' && !vis[i][j])
                cnt++,dfs(i,j);
    cnt++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[i][j])
                v[cnt].push_back(make_pair(i,j));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int te=0;
            for(int z=1;z<4;z++){
                int mn=1e9+9;
                for(auto o:v[z])
                    mn=min(mn,dis(o.first,o.second,i,j));
                te+=mn;
            }
            ans=min(ans,te);
        }

    ans=bfs(1,2)+min(bfs(1,3),bfs(2,3)) ;
    ans=min(ans, bfs(2,3)+min(bfs(1,2),bfs(1,3)));
    ans=min(ans,bfs(1,3)+min(bfs(1,2),bfs(2,3)));
    cout<<ans<<endl;
}