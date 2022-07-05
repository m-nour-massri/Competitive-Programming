//USACO 2017 February Contest, Bronze
//Problem 1. Why Did the Cow Cross the Road I
#include <bits/stdc++.h>
using namespace std;
const int inf=13;
int last[inf];

int main(){
    freopen("crossroad.in","r",stdin);
    freopen("crossroad.out","w",stdout);

    int n,ans=0;
    cin>>n;
    while(n--){
        int cow,side;
        cin>>cow>>side;
        side++;
        if(last[cow] == 0)
            last[cow] = side;
        else if(last[cow]!=side)
            last[cow]=side,ans++;
    }
    cout<<ans<<endl;
}