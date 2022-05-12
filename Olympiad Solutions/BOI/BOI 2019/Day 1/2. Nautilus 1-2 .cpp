//BOI 2019 Day 1 Problem 2 Nautilus
//subtasks: 1-2 66 points
#include <bits/stdc++.h>
using namespace std;
const int inf=109;
int n,m,k,ans;
string grid[inf],directions;
int idx[]={0,0,-1,1};
int idy[]={1,-1,0,0};
map<char ,int> mp;
int dp[inf][inf][inf];

bool valid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=m && grid[x][y]=='.';
}

int main(){

    mp['E']=1,mp['W']=0,mp['N']=3,mp['S']=2;//we reverse the directions
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>grid[i],grid[i]= " "+grid[i];

    cin>>directions;
    directions=" "+directions;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j][0] = valid(i,j);

    for(int z = 1;z<=k;z++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!valid(i,j))
                    continue;
                int x,y;
                if( directions[z] != '?' ){
                    x = i +idx[ mp[ directions[z] ] ],y =j+idy[ mp[ directions[z] ] ];
                    if( valid(x, y ) )
                        dp[i][j][z] |= dp[x][y][z-1];
                }
                for(int dir=0;dir<4 && directions[z] == '?';dir++){
                        x = i+idx[dir],y = j+idy[dir];
                    if( valid( x , y ) )
                        dp[i][j][z] |= dp[x][y][z-1];
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans+=dp[i][j][k];

        cout<<ans<<endl;
}