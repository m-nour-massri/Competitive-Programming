#include <bits/stdc++.h>
using namespace std;
map<string,double> mp;

string in(){
    char s[444];
    scanf("%s",s);
    return string(s);
}

void solve(){
    int c,n;
    double x;
    string a;
    scanf("%d%d",&c,&n);
    for(int i=0;i<c;i++)
        a=in(),scanf("%lf",&x),mp[a]=x;

    mp["JD"]=1.0;

    double ans=0.0;
    for(int i=0;i<n;i++){
        scanf("%lf",&x);
        a=in();
        ans+=x*mp[a];
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    mp.clear();
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}