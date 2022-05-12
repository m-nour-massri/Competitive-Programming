
//USACO 2015 December Contest, Silver
//Problem 1. Switching on the Lights
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9;
vector<pair<int,int> > v[inf][inf];
bool lit[inf][inf],vis[inf][inf];
int idx[]={-1,1,0,0};
int idy[]={0,0,-1,1};
int ans=0,n,m;

bool valid(int x,int y){
    return (x>=1 && y>=1 && x<=n && y<=n);
}
void dfs(int i,int j){
    vis[i][j]=1;

    for(auto o:v[i][j]){

        lit[o.first][o.second]=1;

        for(int z=0;z<4;z++){
            int x=idx[z]+o.first, y=idy[z]+o.second;
            if(valid(x,y) && vis[x][y] && !vis[o.first][o.second])
                dfs(o.first,o.second);
        }
    }
        for(int z=0;z<4;z++){
            int x=idx[z]+i,y=idy[z]+j;
            if(valid(x,y) && lit[x][y] && !vis[x][y])
                dfs(x,y);
        }
}

int main(){

    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v[a][b].push_back(make_pair(c,d));
    }

    lit[1][1]=1;
    dfs(1,1);

    int total=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            total+=lit[i][j];

    cout<<total<<endl;
}
