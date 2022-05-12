
//USACO 2012 November Contest, Silver
//Problem 2. Distant Pastures
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=33,MX=1e9+9;
int n,a,b,ans;
int dis[inf][inf],vis[inf][inf];
int idx[]={0,0,1,-1};
int idy[]={-1,1,0,0};
string arr[inf];
set< pair<int,pair<int,int> > > s;

bool valid(int x,int y){

    return x>=1 && y>=1 && x<=n && y<=n;
}

int main(){

    freopen("distant.in","r",stdin);
    freopen("distant.out","w",stdout);

    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>arr[i],arr[i]=" "+arr[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s.insert(make_pair(0,make_pair(i,j)));
            dis[i][j]=0;
            while(!s.empty()){
                pair<int,pair<int,int> > cur=*s.begin();
                s.erase(s.begin());
                int curx=cur.second.first,cury=cur.second.second;
                if(vis[curx][cury])
                    continue;
                vis[curx][cury]=1;

                for(int z=0;z<4;z++){
                    int x=curx+idx[z],y=cury+idy[z];
                    if(valid(x,y) && dis[x][y]>dis[curx][cury]+(arr[curx][cury]==arr[x][y]?a:b) )
                        dis[x][y]=dis[curx][cury]+(arr[curx][cury]==arr[x][y]?a:b),s.insert(make_pair(dis[x][y],make_pair(x,y)));
                }
            }
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    ans=max(ans,dis[i][j]),dis[i][j]=MX,vis[i][j]=0;
        }
    }
    cout<<ans<<endl;
}