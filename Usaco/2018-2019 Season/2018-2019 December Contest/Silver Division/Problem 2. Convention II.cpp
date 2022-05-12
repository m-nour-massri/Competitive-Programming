
//USACO 2018 December Contest, Silver
//Problem 2. Convention II
#include <bits/stdc++.h>
using namespace std;
const long long  inf=1e5+9;
pair<long long ,long long > a[inf],sor[inf];
set<pair<long long ,long long > > s;
vector<pair<long long ,long long > > v;
long long  in[inf];
int main(){

    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);

    long long  n,mn=1e18+9,ans=0;
    cin>>n;
    for(long long  i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
        sor[i]=make_pair(a[i].second,i);
        mn=min(mn,a[i].second);
    }
    sort(sor+1,sor+1+n);
    long long  l=1;
    long long  ti=0;

    while( (l<=n) || (l>n && s.size()>0)  ){

        if(s.empty()){
            mn=ti=sor[l].first;
            while(sor[l].first==mn && l<=n)
                s.insert(make_pair(sor[l].second,a[sor[l].second].first)),l++;
        }

      pair<long long ,long long > p=*s.begin();

        s.erase(s.find(p));
        ans=max(ans,ti-a[p.first].second);
        in[p.first]=ti;
        ti+=p.second;
        while(l<=n && sor[l].first<=ti)
                s.insert(make_pair(sor[l].second,a[sor[l].second].first)),l++;

    }
    cout<<ans<<endl;

}
