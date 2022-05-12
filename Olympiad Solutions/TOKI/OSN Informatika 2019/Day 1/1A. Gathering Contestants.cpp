//TOKI OSN Open Contest 2019 - Day 1
//1A. Gathering Contestants
#include <bits/stdc++.h>
using namespace std;
const int MX=1e9+9;
int mn=MX,cnt;
vector<vector<int> > par;
int sum(int x1,int y1,int x2,int y2){
    return par[x2][y2] - par[x1-1][y2] - par[x2][y1-1] + par[x1-1][y1-1];
}

int main(){

    int n,m;
    cin>>n>>m;
    par.resize(n+3 , vector<int> (m+3,0) );

    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=1;j<=m;j++)
            par[i][j] = tmp[j-1]-'0',cnt+=par[i][j],par[i][j] += par[i-1][j] + par[i][j-1] - par[i-1][j-1];
    }

    for(int r1=1;r1<=n && n<=m ;r1++){
        for(int r2=r1;r2<=n;r2++){
            int k = r2-r1+1;
            if( cnt % k )
                continue;
            k = cnt/k;
            for(int c=1;c+k-1<=m;c++){
                   mn = min(mn, cnt - sum(r1,c,r2,c+k-1)   );
            }
        }
    }

    for(int c1=1;c1<=m && m<n ; c1++){
        for(int c2=c1;c2<=m;c2++){
            int k = c2-c1+1;
            if( cnt % k )
                continue;
            k = cnt/k;
            for(int r=1;r+k-1<=n;r++){
                mn = min(mn , cnt-sum(r,c1,r+k-1,c2));
            }
        }
    }

    if(mn == MX)
        mn = -1;
    cout<<mn<<endl;
}
