//USACO 2018 US Open Contest, Bronze
//Problem 1. Team Tic Tac Toe

#include <bits/stdc++.h>
using namespace std;
set<char> s[10];
int main(){
    freopen("tttt.in","r",stdin);
    freopen("tttt.out","w",stdout);
    string a[3];
    cin>>a[0]>>a[1]>>a[2];
    int cnt=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            s[cnt].insert(a[i][j]);
        cnt++;
    }
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++)
            s[cnt].insert(a[i][j]);
        cnt++;
    }
    s[cnt].insert(a[1][1]);
    s[cnt].insert(a[0][0]);
    s[cnt].insert(a[2][2]);
    cnt++;
    s[cnt].insert(a[1][1]);
    s[cnt].insert(a[0][2]);
    s[cnt].insert(a[2][0]);
    cnt++;
    set<char> ans1;
    set<pair<char,char> > ans2;
    for(int i=1;i<cnt;i++){
        if(s[i].size()==1)
            ans1.insert(*s[i].begin());
        if(s[i].size()==2){
            set<char> ::iterator it=s[i].begin();
            it++;
            ans2.insert(make_pair(*s[i].begin(),*it));
        }
    }
    cout<<ans1.size()<<endl<<ans2.size()<<endl;
}