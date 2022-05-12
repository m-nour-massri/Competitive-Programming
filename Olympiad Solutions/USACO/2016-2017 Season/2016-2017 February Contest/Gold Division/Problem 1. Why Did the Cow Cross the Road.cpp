//USACO 2017 February Contest, Gold
//Problem 1. Why Did the Cow Cross the Road
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9,MX=1e9+9;
int a[inf][inf],vis[inf][inf][4],dis[inf][inf][5],n,t;
int idx[]={0,0,-1,1};
int idy[]={1,-1,0,0};

bool valid(int x,int y){
    return x>0 && y>0 && x<=n && y<=n;
}

int main(){

    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out,"w",stdout);

    cin>>n>>t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j],dis[i][j][0]=dis[i][j][1]=dis[i][j][2]=MX;

    set<pair<pair<int,int> ,pair<int,int> > > s;
    s.insert(make_pair( make_pair(0,0),make_pair(1,1)  ));
    dis[1][1][0]=0;
    while(!s.empty()){
        pair<pair<int,int> ,pair<int,int> > p=*s.begin();
        s.erase(s.begin());
        int i=p.second.first,j=p.second.second,ti=p.first.second;
        if(vis[i][j][ti])
            continue;

        for(int z=0;z<4;z++){
            int x=i+idx[z],y=j+idy[z];
            if(valid(x,y) && dis[x][y][(ti+1)%3] > t+dis[i][j][ti]+(ti==2)*a[x][y])
                dis[x][y][(ti+1)%3]=t+dis[i][j][ti]+(ti==2)*a[x][y],
                s.insert(make_pair( make_pair(dis[x][y][(ti+1)%3],  (ti+1)%3    ),  make_pair(x,y)  ));
        }
    }
    cout<<min(dis[n][n][0],  min(dis[n][n][1]  ,dis[n][n][2] ))<<endl;
}