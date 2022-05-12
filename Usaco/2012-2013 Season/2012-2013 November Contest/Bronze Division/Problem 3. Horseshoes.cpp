
//USACO 2012 November Contest, Bronze
//Problem 3. Horseshoes
#include <bits/stdc++.h>
using namespace std;
const int inf=7;
int n,ans;
bool vis[inf][inf];
int idx[]={0,0,-1,1};
int idy[]={1,-1,0,0};
string a[inf];

bool valid(int x,int y){
    return x>=1 && y>=1 && x<=n && y<=n;
}

void calc(int i,int j,int open,int close,bool closing){

    if(open==close)
        return void(ans=max(ans,open+close));

    if(closing && (open+open)<=ans)
        return ;

    vis[i][j]=1;

    for(int z=0;z<4;z++){
        int x=idx[z]+i,y=idy[z]+j;
        if(!valid(x,y) || vis[x][y])
            continue;
        if(a[x][y]==')')
            calc(x,y,open,close+1,1);
        if(a[x][y]=='(' && !closing)
            calc(x,y,open+1,close,0);
    }
    vis[i][j]=0;
}

int main(){

    freopen("hshoe.in","r",stdin);
    freopen("hshoe.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]=" "+a[i];

    if(a[1][1]=='(')
        calc(1,1,1,0,0);
    cout<<ans<<endl;
}