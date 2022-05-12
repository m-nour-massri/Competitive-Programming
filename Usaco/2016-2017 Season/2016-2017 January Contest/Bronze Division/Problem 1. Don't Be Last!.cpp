//USACO 2017 January Contest, Bronze
//Problem 1. Don't Be Last!
#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;

int main(){

    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        int val;
        cin>>tmp>>val;
        mp[tmp]+=val;
    }
    multiset<int> s;
    for(auto o:mp){
        s.insert(o.second);
    }
    int x=0;
    if(mp.size() == 7){
     x=*s.begin();
        s.erase(x);

    }
    if(s.empty())
        cout<<"Tie"<<endl,exit(0);
    x=*s.begin();
    if(s.count(x)>1)
        cout<<"Tie"<<endl,exit(0);
    for(auto o:mp)
        if(o.second == x)
            cout<<o.first<<endl,exit(0);
}