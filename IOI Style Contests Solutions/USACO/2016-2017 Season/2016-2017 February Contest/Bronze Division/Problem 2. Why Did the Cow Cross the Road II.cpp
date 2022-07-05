
//USACO 2017 February Contest, Bronze
//Problem 2. Why Did the Cow Cross the Road II
#include <bits/stdc++.h>
using namespace std;
const int inf=777;
pair<int,int> pos[inf];
string a;
int ans;

int main(){

    freopen("circlecross.in","r",stdin);
    freopen("circlecross.out","w",stdout);

    cin>>a;
    for(int i=0;i<a.size();i++)
        if(pos[ a[i]-'A' ].first == 0)
            pos[a[i]-'A'].first = i+1;
        else if(pos[ a[i]-'A' ].second == 0)
            pos[a[i]-'A'].second=i+1;

    sort(pos,pos+26);
    for(int i=0;i<26;i++)
        for(int j=0;j<i;j++)
            ans+=pos[i].second>pos[j].second && pos[j].second>pos[i].first;

    cout<<ans<<endl;
}