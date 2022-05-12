// IOI team 4.Find the Treasure (islands)
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e3+9;
int idx[] = {1,-1,0,0};
int idy[] = {0,0,-1,1};
int n,m;
bool a[inf][inf],vis[inf][inf],is = 0;

void dfs(int i,int j){
    is |= (i==n || i==1 || j==1 || j == m);
    vis[i][j] = 1;

    for(int z=0;z<4;z++){
        int x = idx[z] + i,y = idy[z] + j;
        if(x>=1 && x<=n && y>=1 && y<=m && a[x][y] ==1 && vis[x][y] == 0)
            dfs(x,y);
    }
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j] || a[i][j] == 0)
                continue;
            is = 0;
            dfs(i,j);
            ans += !is;
        }
    }
    cout<<ans<<endl;
}