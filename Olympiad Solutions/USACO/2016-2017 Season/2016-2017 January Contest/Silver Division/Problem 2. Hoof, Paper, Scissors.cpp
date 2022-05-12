//USACO 2017 January Contest, Silver
//Problem 2. Hoof, Paper, Scissors
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;

int n,dp[inf][3][2],a[inf];
map<char,int> mp;

int solve(int idx,int type,bool change){

    if(idx==n+1)
        return 0;

    int &ret=dp[idx][type][change];
    if(ret != -1)
        return ret;

    ret =( (type+1)%3 == a[idx] )+solve(idx+1,type,change);
    for(int i=0;i<3 && !change;i++)
            ret=max(ret,( (type+1)%3 == a[idx] )+solve(idx+1,i,1));

    return ret;

}

int main(){

    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    mp['H']=0;
    mp['S']=1;
    mp['P']=2;
    //every letter x beats (x+1)%3

    cin>>n;
    for(int i=1;i<=n;i++){
        char tmp;
        cin>>tmp;
        a[i]=mp[tmp];
    }
    memset(dp,-1,sizeof(dp));
    cout<<max(solve(1,0,0) , max(solve(1,1,0) , solve(1,2,0) ) )<<endl;
}