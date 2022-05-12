//USACO 2017 February Contest, Silver
//Problem 3. Why Did the Cow Cross the Road
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int n,m,k,is[inf][inf],vis[inf][inf],ans,ts,cur;
set<pair<int,int> > s[inf][inf];
pair<int,int> a[inf];
int idx[]={-1,1,0,0};
int idy[]={0,0,-1,1};

void dfs(int i,int j){

    vis[i][j]=ts;
    cur+=is[i][j];

    for(int z=0;z<4;z++){
        int x=i+idx[z],y=j+idy[z];
        if(x>0 && y>0 && x<=n && y<=n && s[i][j].find(make_pair(x,y))==s[i][j].end()  && vis[x][y]!=ts)
            dfs(x,y);
    }

}

int main(){

    freopen("countcross.out","w",stdout);
    freopen("countcross.in","r",stdin);

    cin>>n>>m>>k;

    while(k--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        s[x1][y1].insert(make_pair(x2,y2));
        s[x2][y2].insert(make_pair(x1,y1));
    }

    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
        is[a[i].first][a[i].second]=1;
    }

    for(int i=1;i<=m;i++){
        ++ts;
        cur=0;
        dfs(a[i].first,a[i].second);
        ans+=m-1-cur+1;
    }
    cout<<ans/2<<endl;
}