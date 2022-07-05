//USACO 2017 January Contest, Gold
//Problem 3. Cow Navigation
#include <bits/stdc++.h>
using namespace std;
const int inf=22;

struct state{
    int x1,y1,dir1;
    int x2,y2,dir2;
};
int idx[]={0,-1,0,1};
int idy[]={-1,0,1,0};
//dir = 0 ->left
//dir = 1 -> up
//dir = 2 -> right
//dir = 3 -> down
//turning left -1
//turn right +1

int n;
bool grid[inf][inf];//0 denotes empty and 1 denotes hay bale
queue<state> q;
bool vis[inf][inf][4][inf][inf][4];
int dis[inf][inf][4][inf][inf][4];

bool valid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=n && !grid[x][y];
}
bool Vis(state cur){
    return vis[cur.x1][cur.y1][cur.dir1][cur.x2][cur.y2][cur.dir2];
}
void MVis(state cur){
     vis[cur.x1][cur.y1][cur.dir1][cur.x2][cur.y2][cur.dir2] = 1;
}
int Dis(state cur){
     return dis[cur.x1][cur.y1][cur.dir1][cur.x2][cur.y2][cur.dir2];
}
void MDis(state cur,int d){
    dis[cur.x1][cur.y1][cur.dir1][cur.x2][cur.y2][cur.dir2] = d;
}

int main(){

    freopen("cownav.in","r",stdin);
    freopen("cownav.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=1;j<=n;j++)
            grid[i][j] = (tmp[j-1] == 'H');
    }

    memset(dis,21,sizeof(dis));
    //lower left cell is (n,1)
    state Start = {n,1,1,n,1,2};//right and up
    q.push(Start);
    MDis(Start,0);

    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if( Vis(cur) )
            continue;
        MVis(cur);

        if(cur.x1 == 1 && cur.y1 == n && cur.x2 == 1 && cur.y2 == n)//upper right cell is (1,n)
            cout<<Dis(cur)<<endl,exit(0);

        state TurnLeft = { cur.x1,cur.y1, (cur.dir1-1+4)%4 , cur.x2 , cur.y2 , (cur.dir2-1+4)%4 };
        if( Dis(TurnLeft) > Dis(cur)+1 )
            MDis(TurnLeft , Dis(cur)+1),q.push(TurnLeft);

        state TurnRight = { cur.x1,cur.y1, (cur.dir1+1)%4 , cur.x2 , cur.y2 , (cur.dir2+1)%4 };
        if( Dis(TurnRight) > Dis(cur)+1 )
            MDis(TurnRight , Dis(cur)+1),q.push(TurnRight);

        state Forward=cur;
        int d,x,y;
        d = cur.dir1; x=cur.x1+idx[d],y=cur.y1+idy[d];
        if(valid(x,y) && !(cur.x1 == 1 && cur.y1 == n))//the cow stops when it reachs the end and don't move to an invalid cell
            Forward.x1 = x , Forward.y1 = y;

        d = cur.dir2; x=cur.x2+idx[d],y=cur.y2+idy[d];
        if(valid(x,y) && !(cur.x2 == 1 && cur.y2 == n))//the cow stops when it reachs the end and don't move to an invalid cell
            Forward.x2 = x , Forward.y2 = y;
        if( Dis(Forward) > Dis(cur)+1 )
            MDis(Forward , Dis(cur)+1),q.push(Forward);
    }

}