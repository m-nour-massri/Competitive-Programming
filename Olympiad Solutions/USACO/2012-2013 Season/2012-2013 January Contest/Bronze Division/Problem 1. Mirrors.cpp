//USACO 2013 January Contest, Bronze
//Problem 1. Mirrors
#include <bits/stdc++.h>
using namespace std;
const int inf=209;
int n,a,b;
int x[inf],y[inf];
char type[inf];

bool check(){
    bool vis[inf][6]={0};

    int curx=0,cury=0,dir=1,cur=0;
    //1.right 2.left 3.up 4.down

    while(!vis[cur][dir]){

        if(curx==a && cury==b)
            return 1;
        vis[cur][dir]=1;
        int idx=0;

        for(int i=1;i<=n && dir==1; i++)
            if(cury < y[i] && curx==x[i] && (idx==0 || y[idx]>y[i]) )
                idx=i;
        for(int i=1;i<=n && dir==2;i++)
            if(cury > y[i] && curx==x[i] && (idx==0 || y[idx]<y[i]) )
                idx=i;
        for(int i=1;i<=n && dir==3;i++)
            if(curx < x[i] && cury==y[i] && (idx==0 || x[idx]>x[i]) )
                idx=i;
        for(int i=1;i<=n && dir==4;i++)
            if(curx > x[i] && cury==y[i] && (idx==0 || x[idx]<x[i]) )
                idx=i;

        curx=x[idx],cury=y[idx],cur=idx;
        if(type[idx]=='B')
            return 1;
        if(idx==0)
            return 0;

        if(  (dir==1 && type[idx]=='/') || (dir==2 && type[idx]=='\\') )//up
            dir=3;
        else if(  (dir==2 && type[idx]=='/') || (dir==1 && type[idx]=='\\') )//down
            dir=4;
        else if(  (dir==3 && type[idx]=='/') || (dir==4 && type[idx]=='\\') )//right
            dir=1;
        else if( (dir==4 && type[idx]=='/') || (dir==3 && type[idx]=='\\') )//left
            dir=2;

    }
    return 0;
}

int main(){

    freopen("mirrors.in","r",stdin);
    freopen("mirrors.out","w",stdout);

    cin>>n>>a>>b;
    swap(a,b);
    for(int i=1;i<=n;i++)
        cin>>y[i]>>x[i]>>type[i];

    n++;
    x[n]=a,y[n]=b,type[n]='B';

    //we swap x[i] and y[i] , a and b because we assume that x is the row and y is column
    for(int i=0;i<n;i++){
        if(type[i]=='/')
            type[i]='\\';
        else
            type[i]='/';

        if(check())
            cout<<i<<endl,exit(0);

        if(type[i]=='/')
            type[i]='\\';
        else
            type[i]='/';
    }
    cout<<-1<<endl;
}