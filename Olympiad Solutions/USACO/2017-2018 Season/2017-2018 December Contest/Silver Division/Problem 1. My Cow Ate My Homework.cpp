//USACO 2017 December Contest, Silver
//Problem 1. My Cow Ate My Homework
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=2e5+9;
ll  a[inf];
pair<ll ,ll > ans[inf],mx;
//ans[i] denotes the answer if we consider k= i-1
int  main(){
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    ll  n;
    cin>>n;
    for(ll  i=1;i<=n;i++)
        cin>>a[i];

    ll mn=a[n],sum=a[n];

    for(ll i=n-1;i>1;i--){

        mn=min(mn,a[i]),sum+=a[i];

         ans[i]=make_pair(sum-mn,n-i);

        if(mx.first*ans[i].second <= mx.second*ans[i].first   )
            mx=ans[i];
    }
    bool before=0;
    for(ll i=2;i<=n-1;i++)
        if(mx.first*ans[i].second == mx.second*ans[i].first   )
            cout<<i-1<<endl;
}