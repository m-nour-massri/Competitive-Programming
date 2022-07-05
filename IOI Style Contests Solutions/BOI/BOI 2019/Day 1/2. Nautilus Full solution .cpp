
//BOI 2019 Day 1 Problem 2 Nautilus
//full solution subtasks: 1-3 100 points
#include <bits/stdc++.h>
using namespace std;
const int inf=509;
int n,m,k,ans;
string grid[inf],directions;

int idx[]={0,0,-1,1};
int idy[]={1,-1,0,0};
bitset<inf> dp[inf][inf*10],sea[inf];


int main(){

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>grid[i],grid[i]= " "+grid[i];

    cin>>directions;
    directions=" "+directions;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sea[i][j] = (grid[i][j] == '.'),dp[i][0][j] = (grid[i][j] == '.');

    for(int z = 1;z<=k;z++){
        for(int i=1;i<=n;i++){

            if(directions[z] != '?'){
                if(  directions[z]  == 'N' )//we reverse directions W<->E , S<->N
                    dp[i][z] = dp[i + 1 ][z-1] ;
                else if( directions[z] == 'S' )
                    dp[i][z] = dp[i-1][z-1];
                else if( directions[z] == 'E' )
                    dp[i][z] = (dp[i][z-1] <<1 );
                else
                    dp[i][z] = (dp[i][z-1] >> 1);
            }
            else{
                dp[i][z] = dp[i -1][z-1] | dp[i+1][z-1] | (dp[i][z-1] << 1) | (dp[i][z-1] >> 1);
            }
            dp[i][z] &= sea[i];
        }
    }

    for(int i=1;i<=n;i++)
            ans+=dp[i][k].count();

    cout<<ans<<endl;
}