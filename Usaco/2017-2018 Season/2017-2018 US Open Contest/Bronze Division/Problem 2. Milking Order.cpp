//USACO 2018 US Open Contest, Bronze
//Problem 2. Milking Order
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int a[inf],pos[inf],id[inf];
int main(){
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    int n,m,k,ss=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        if(a[i]==1)
            ss=i;
    }

    while(k--){
        int x,y;
        cin>>x>>y;
        id[y]=x;
        pos[x]=y;
        if(x==1)
            cout<<y,exit(0);
    }
    if(ss){
        int l=1;
        int cur=max(1,pos[a[1]] );
        while(cur<=n && l<=m){
            if(cur==pos[a[l]]){
                   cur++;
                   l++;
                   continue;
                }
            if(id[cur]){
                cur++;
                continue;
            }
            id[cur]=a[l];
            if(a[l]==1)
                cout<<cur,exit(0);
            l++;
            cur=max(cur+1,pos[a[l]] );
        }
    }


    bool b=0;

    for(int i=1;i<=m;i++){
        if(pos[a[i]]){
            b=1;
            int cur=pos[a[i]]-1,l=i-1;
            a[i]=0;
            while(cur>=1 && l>0 && a[l]){
                if(id[cur])
                    cur--;
                else id[cur]=a[l],a[l]=0,l--;
            }
        }
    }
    if(!b){
        int cur=n,l=m;
            while(cur>=1 && l>0 && a[l]){
                if(id[cur])
                    cur--;
                else id[cur]=a[l],a[l]=0,l--;
            }
    }
    for(int i=1;i<=n;i++)
        if(id[i]==0)
            cout<<i,exit(0);
}