
//USACO 2018 US Open Contest, Silver
//Problem 1. Out of Sorts

#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
pair<int,int> a[inf];
int c[inf];
bool cmp(pair<int,int> x,pair<int,int> y){
    return x.second<y.second;
}

int main(){
    //freopen("sort.in","r",stdin);
    //freopen("sort.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        c[a[i].second]=i;
    sort(a+1,a+1+n,cmp);
    int mx=0;
    for(int i=1;i<=n;i++){
        if(c[i]<i)
            mx=max(mx,i-c[i]);
    }
    cout<<mx+1<<endl;
}
