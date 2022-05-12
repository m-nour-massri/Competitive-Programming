
//USACO 2018 December Contest, Silver
//Problem 3. Mooyo Mooyo
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
string a[inf];
bool vis[inf][13];
int idx[]={-1,1,0,0};
int idy[]={0,0,-1,1};
int n,k;
vector<pair<int,int> > v;

bool valid(int x,int y){
    return (x>=0 && y>=0 && x<n && y<10 && a[x][y]!='0');
}

void dfs(int i,int j){

    vis[i][j]=1;
    v.push_back(make_pair(i,j));
    for(int z=0;z<4;z++){
        int x=i+idx[z],y=j+idy[z];
        if(valid(x,y) && a[i][j]==a[x][y] && !vis[x][y])
           dfs(x,y);
    }
}

void gravity(int x){
    vector<char> ss;
    for(int i=0;i<n;i++)
        if(a[i][x]!='0')
            ss.push_back(a[i][x]);
    for(int i=n-1;i>=0;i--){
        if(ss.empty())
            a[i][x]='0';
        else {
            a[i][x]=ss.back();
            ss.pop_back();
        }
    }
}


int main(){
    freopen("mooyomooyo.out","w",stdout);
    freopen("mooyomooyo.in","r",stdin);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cnt=1;
    while(1){
        bool te=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                if(valid(i,j))
                    dfs(i,j);
                if(v.size()>=k){
                    te=1;
                    for(auto o:v)
                        a[o.first][o.second]='0',vis[o.first][o.second]=0;
                }
                for(auto o:v)
                    vis[o.first][o.second]=0;

                v.clear();
            }
        }

        if(te==0)
            break;
        for(int i=0;i<10;i++)
            gravity(i);

    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}