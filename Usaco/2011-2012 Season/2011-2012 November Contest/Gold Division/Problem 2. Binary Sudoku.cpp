//USACO 2011 November Contest, Gold Division Problem 2. Binary Sudoku
///dp with bitmasking
#include <bits/stdc++.h>
using namespace std;
const int MX=1e9+9;
int a[10][10], dp[9][9][(1<<9)][(1<<3)][2];

int solve(int r,int c,int cmask,int sqmask,bool rm){
    if(r==9){
        return (cmask?MX:0);
    }
    if(c==9){
        if(rm)
            return MX;
        if( r%3==2 && sqmask )
            return MX;
        return solve(r+1,0,cmask,sqmask,0);
    }
    int &ret=dp[r][c][cmask][sqmask][rm];
    if(ret!=-1)
        return ret;
    int ret1,ret2;
    ret1=!a[r][c]+solve(r,c+1,cmask^(1<<c),sqmask^(1<<(c/3)),!rm  );
    ret2=a[r][c]+solve(r,c+1,cmask,sqmask,rm);

    return ret=min(ret1,ret2);
}

int main(){
        for(int i=0;i<9;i++){
            string s;
            cin>>s;
            for(int j=0;j<9;j++)
                a[i][j]=(s[j]=='1');
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,0,0,0)<<endl;
}