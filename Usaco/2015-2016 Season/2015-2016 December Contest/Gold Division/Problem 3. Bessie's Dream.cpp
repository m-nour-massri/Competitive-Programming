//USACO 2015 December Contest, Gold
//Problem 3. Bessie's Dream
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9;
struct state{
    int x,y,slide,smell;
};
queue<state> q;
int n,m,a[inf][inf],dis[inf][inf][6][2],vis[inf][inf][6][2];
int idx[]={0,0,-1,1};
int idy[]={-1,1,0,0};
//0-up , 1-down , 2-left , 3-right

void UpDis( state cur , int d ){
    dis[cur.x][cur.y][cur.slide][cur.smell]=d;
}
int Dis( state cur ){
    return dis[cur.x][cur.y][cur.slide][cur.smell];
}

bool CanDir(state &cur,int dir){

    cur.x+=idx[dir],cur.y+=idy[dir];
    if(cur.x<1 || cur.x>n || cur.y<1 || cur.y>m || a[cur.x][cur.y] == 0)
        return 0;
    if(a[cur.x][cur.y] == 3 && cur.smell==0)
        return 0;
    if(a[cur.x][cur.y] == 1)
        cur.slide=4;
    else if(a[cur.x][cur.y] == 2)
        cur.smell=1,cur.slide=4;
    else if(a[cur.x][cur.y] == 3)
        cur.slide=4;
    else if(a[cur.x][cur.y] == 4)
        cur.smell=0,cur.slide=dir;

    return 1;
}

void go(state to, state cur, int add){

    if(Dis(cur)+add < Dis(to) )
        UpDis(to,Dis(cur)+add),q.push(to);
}

int main(){

   freopen("dream.in","r",stdin);
   freopen("dream.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    memset(dis,21,sizeof(dis));
    state cur={1,1,4,0};
    q.push(cur);
    UpDis(cur,0);
    while(!q.empty()){
        cur=q.front();
        q.pop();

        if(cur.x == n && cur.y == m)
            cout<<Dis(cur)<<endl,exit(0);
        state to =cur;
        if(cur.slide<4 && CanDir(to,cur.slide)){
            go(to , cur , 1);
            continue;
        }

        for(int z=0;z<4;z++){
            to=cur;
            if(CanDir(to,z))
                go(to,cur,1);
        }
    }

    cout<<-1<<endl;
}