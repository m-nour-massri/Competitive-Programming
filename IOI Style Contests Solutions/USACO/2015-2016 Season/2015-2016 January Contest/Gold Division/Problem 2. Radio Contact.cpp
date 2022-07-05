//USACO 2016 January Contest, Gold
//Problem 2. Radio Contact
#include <bits/stdc++.h>
using namespace std;
const int inf=1e3+9,MX=1e9+9;
int n,m,X1,Y1,X2,Y2;
string a,b;
int prex1[inf],prey1[inf],prex2[inf],prey2[inf],dp[inf][inf];

int dis(int pos1,int pos2){

    int x=abs(prex1[pos1]-prex2[pos2]),y=abs(prey1[pos1]-prey2[pos2]);
    return x*x+y*y;
}
int solve(int pos1,int pos2){

    if(pos1 > n || pos2 > m)
        return MX;

    if(pos1 == n && pos2 == m)
        return dis(pos1,pos2);

    int &ret=dp[pos1][pos2];
    if(ret!=-1)
        return ret;
    ret=min( solve(pos1+1,pos2+1) , min(solve(pos1+1,pos2) , solve(pos1,pos2+1)) )+dis(pos1,pos2);
    return ret;
}

int main(){

    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);

    cin>>n>>m>>X1>>Y1>>X2>>Y2>>a>>b;
    prex1[0]=X1,prey1[0]=Y1,prex2[0]=X2,prey2[0]=Y2;

    for(int i=1;i<=n;i++)
        prex1[i]=prex1[i-1]+(a[i-1] =='E')-(a[i-1] =='W'),
        prey1[i]=prey1[i-1]+(a[i-1] =='N')-(a[i-1] =='S');

    for(int i=1;i<=m;i++)
        prex2[i]=prex2[i-1]+(b[i-1] =='E')-(b[i-1] =='W'),
        prey2[i]=prey2[i-1]+(b[i-1] =='N')-(b[i-1] =='S');

    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)-dis(0,0)<<endl;
}