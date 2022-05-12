//USACO 2016 January Contest, Platinum
//Problem 1. Fort Moo
#include <bits/stdc++.h>
using namespace std;
const int inf=2e2+9;
int par[inf][inf],m,n,a[inf][inf],ans;

int sum (int x1,int y1,int x2,int y2){
    return par[x2][y2]-par[x1-1][y2]-par[x2][y1-1]+par[x1-1][y1-1];
}

void build(int n,int m)
{
   for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j)
	   par[i][j]=a[i][j]+par[i-1][j]+par[i][j-1]-par[i-1][j-1];
}


int main(){

    freopen("fortmoo.out","w",stdout);
    freopen("fortmoo.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string te;
        cin>>te;
        te=" "+te;
        for(int j=1;j<=m;j++)
            a[i][j]=(te[j]=='X');
    }

    build(n,m);

    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){

            int last=1;

            for(int z=1;z<=m;z++){

                int a=sum(i,last,i,z),b=sum(i,last,j,last),c=sum(j,last,j,z),d=sum(i,z,j,z);

                if(a==0 && b==0 && c==0 && d==0)
                    ans=max(ans,(z-last+1)*(j-i+1));
                if(a || b || c)
                    last=z;

            }
        }
    }
    cout<<ans<<endl;
}