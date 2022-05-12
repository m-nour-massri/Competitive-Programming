
//USACO 2013 January Contest, Silver
//Problem 2. Square Overlap
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=5e4+9;
ll n,k,y,x;
pair<ll,ll> a[inf];
vector<pair<pair<ll,ll> ,pair<ll,ll> > > res;
set<pair<ll,ll> > s;

int main(){

    freopen("squares.in","r",stdin);
    freopen("squares.out","w",stdout);

    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;

    sort(a+1,a+1+n);

    ll r=0;
        for(ll i=1;i<=n && res.size()<2;i++){

        while(r<n && a[r+1].first<a[i].first+k)
            r++,s.insert(make_pair(a[r].second,a[r].first));

        set<pair<ll,ll> > ::iterator it;

        s.erase(make_pair(a[i].second,a[i].first));
        pair<ll,ll> temp;
        if(s.empty())
            continue;

        it=s.lower_bound(make_pair(a[i].second,a[i].first));
        if(it!=s.end()){
            temp=*it;
            swap(temp.first,temp.second);
            y=min(temp.second,a[i].second),x=max(temp.second,a[i].second);
            // this is for the case that temp.second<a[i].second (after swapping)

        if(x<y+k)
            res.push_back(make_pair(a[i],temp));
        }

        if(it==s.begin())
            continue;
        it--;
        temp=*it;
        swap(temp.first,temp.second);
        y=min(temp.second,a[i].second),x=max(temp.second,a[i].second);
        if(x<y+k)
            res.push_back(make_pair(a[i],temp));
    }

    if(res.size()>1)
        cout<<-1<<endl,exit(0);
    else if(res.size()==0)
        cout<<0<<endl,exit(0);

    ll dx=abs(res[0].first.first-res[0].second.first);
    ll dy=abs(res[0].first.second-res[0].second.second);
    cout<<1ll*(k-dy)*(k-dx)<<endl;
}