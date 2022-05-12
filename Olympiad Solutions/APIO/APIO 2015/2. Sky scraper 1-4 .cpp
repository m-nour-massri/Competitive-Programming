//APIO 2015 Sky scraper
//1-4 subtasks solution 57 points
#include <bits/stdc++.h>
using namespace std;
const int inf=2e3+9,M=3e4+9;
int n,m;
int building[M],speed[M],dis[inf][inf][2];//dis[building][speed]
bool vis[inf][inf][2];
vector<int> dogs[inf];
struct State{

    int B,S;
    bool Pass;
};
deque<State>q;

int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",building+i,speed+i),building[i]++,dogs[building[i]].push_back(i);

    memset(dis,21,sizeof(dis));

    int goal=building[2];

    dis[building[1]][speed[1]][0]=0;
    q.push_front({building[1],speed[1],0});

    while(!q.empty()){
        State cur=q.front();
        q.pop_front();

        if(vis[cur.B][cur.S][cur.Pass])
            continue;
        vis[cur.B][cur.S][cur.Pass]=1;
        if(cur.B==goal)
            printf("%d\n",dis[cur.B][cur.S][cur.Pass]),exit(0);

        if(!cur.Pass){
            dis[cur.B][cur.S][1]=dis[cur.B][cur.S][0];
            q.push_front({cur.B,cur.S,1});

            for(auto o:dogs[cur.B])
                if(dis[ building[o] ][ speed[o] ] [1] >= dis[ cur.B ] [ cur.S ] [cur.Pass] )
                    dis[ building[o] ][ speed[o] ] [1] = dis[ cur.B ] [ cur.S ] [cur.Pass],
                    q.push_front(  {building[o],speed[o],1} );
            continue;
        }

        if(cur.B+cur.S<=n && dis[ cur.B+cur.S ][ cur.S ][0]> dis[cur.B][cur.S][cur.Pass]+1 )
            dis[ cur.B+cur.S ][ cur.S ][0] = dis[cur.B][cur.S][cur.Pass]+1,
            q.push_back({cur.B+cur.S , cur.S , 0});

        if(cur.B - cur.S >=1 && dis[cur.B-cur.S] [ cur.S ][0] > dis[cur.B] [cur.S] [cur.Pass]+1)
            dis[cur.B-cur.S] [ cur.S ][0] = dis[cur.B] [cur.S] [cur.Pass]+1,
            q.push_back({cur.B-cur.S , cur.S , 0});
    }

    printf("-1\n");
}