//USACO 2013 January Contest, Bronze
//Problem 3. Liars and Truth Tellers
#include <bits/stdc++.h>
using namespace std;
const int inf=2e3+9;

int n,m,par[inf],sz[inf];

int root(int x){

    if(x==par[x])
        return x;
    return par[x]=root(par[x]);
}

void join(int x,int y){

    x=root(x);
    y=root(y);
    if(x==y)
        return ;
    if(sz[x]>sz[y])
        swap(x,y);
    par[x]=y;
    sz[y]+=sz[x];
}

bool same(int x,int y){
    return (x>n?x-n:x)==(y>n?y-n:y);
}

//"x y T", x and y must be of the same type
//"x y L" x and y are of different type
//people in the component x are the same as x
//people in the component x+n are not the same as x

int main(){

    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n+n;i++)
        par[i]=i,sz[i]=1;

    for(int i=1;i<=m;i++){
        int x,y;
        char type;
        cin>>x>>y>>type;
        if(type=='T'){
            if( same(root(x),root(y)) ){// in the same component (x or x+n)
                if( root(x)!=root(y) ) // not the same state
                    cout<<i-1<<endl,exit(0);
            }
            else {
                join(x,y);
                join(x+n,y+n);
            }
        }
        else {
            if( same(root(x),root(y)) ){// in the same component (x or x+n)
                if( root(x)==root(y) ) // the same state
                    cout<<i-1<<endl,exit(0);
            }
            else {
                join(x,y+n);
                join(x+n,y);
            }
        }
    }
    cout<<m<<endl;
}