//USACO 2016 December Contest, Silver
//Problem 2. Cities and States
#include <bits/stdc++.h>
using namespace std;
map<pair<string,string> ,long long >mp;
int main(){
    freopen("citystate.in","r",stdin);freopen("citystate.out","w",stdout);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        a=a.substr(0,2);
        if(a==b)
            continue;
        ans+=mp[make_pair(b,a)];
        mp[make_pair(a,b)]++;
    }
    cout<<ans<<endl;
}
