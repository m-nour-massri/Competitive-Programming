//USACO 2017 US Open Contest, Silver
//Problem 3. Where's Bessie?
#include <bits/stdc++.h>
using namespace std;
const int inf=22;
int n,ans;
int c1,c2,r1,r2;
string a[inf];
set< pair<int,int> >EndPoints;
vector< pair< pair<int,int> , pair<int,int> > > PCL;
int idx[]={-1,1,0,0};
int idy[]={0,0,-1,1};
bool vis[inf][inf];

map<char,int> oc;

bool valid(int x,int y){
    return x>=r1 && x<=r2 && y>=c1 && y<=c2 && !vis[x][y];
}

void dfs(int i,int j,char cur){

    if(!valid(i,j) || a[i][j] != cur)
        return ;
    vis[i][j]=1;
    for(int z=0;z<4;z++)
        dfs(i+idx[z],j+idy[z],cur);
}
//is x inside y
bool inside(pair< pair<int,int> , pair<int,int> > x ,pair< pair<int,int> , pair<int,int> > y){

     return x.first.first>=y.first.first && x.first.second>=y.first.second &&
                x.second.first<=y.second.first && x.second.second<=y.second.second;
}

int main(){

    freopen("where.out","w",stdout);
    freopen("where.in","r",stdin);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=" "+a[i];

    for( r1=1;r1<=n;r1++){
        for( c1=1;c1<=n;c1++){
            for( r2=r1;r2<=n;r2++){
                for( c2=c1;c2<=n;c2++){
                    oc.clear();
                    bool one=0,mul=0;
                    memset(vis,0,sizeof(vis));
                    for(int i=r1;i<=r2;i++)
                        for(int j=c1;j<=c2;j++)
                            if(!vis[i][j])
                                dfs(i,j,a[i][j]), oc[a[i][j]] ++;
                    if( oc.size()!=2 )
                        continue;
                    for(auto o:oc)
                        if(o.second ==1)
                            one = 1;
                        else if(o.second>1)
                            mul=1;
                    if(mul && one)
                        PCL.push_back( make_pair( make_pair(r1,c1) , make_pair(r2,c2) ) );
                }
            }
        }
    }

    for(int i=0;i<PCL.size();i++){
        bool tr=1;
        for(int j=0;j<PCL.size();j++)
            if(i!=j && inside(PCL[i],PCL[j]))//is i inside j
                tr=0;
        ans+=tr;
    }
    cout<<ans<<endl;
}