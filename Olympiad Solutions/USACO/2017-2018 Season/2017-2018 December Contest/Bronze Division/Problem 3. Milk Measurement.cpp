//USACO 2017 December Contest, Bronze
//Problem 3. Milk Measurement
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
map<string,int> cow;
pair<pair<int,int>,string> a[inf];
multiset<int> s;
int main(){

    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first.first>>a[i].second>>a[i].first.second,cow[a[i].second];

    sort(a+1,a+1+n);

    for(int i=1;i<=cow.size();i++)
        s.insert(0);

    int ans=0;
    for(int i=1;i<=n;i++){

        string S=a[i].second;
        int add=a[i].first.second;
        int old=cow[S];
        int New=cow[S]+add;
        cow[S]+=add;

        s.erase(s.find(old));

        int mx=*s.rbegin();

        if(New >old){
            if( (New > mx && old>mx) || (New<mx && old<mx));
            else
                ans++;
        }
        else {
            if( (New > mx && old>mx) || (New<mx && old<mx));
            else
                ans++;
        }
        s.insert(New);
    }
    cout<<ans<<endl;
}