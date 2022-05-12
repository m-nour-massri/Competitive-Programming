//USACO 2017 February Contest, Gold
//Problem 3. Why Did the Cow Cross the Road III
//naive solution
#include <bits/stdc++.h>
using namespace std;
const int inf=5e4+9;
pair<int,int> a[inf];

int main(){

    freopen("circlecross.out","w",stdout);
    freopen("circlecross.in","r",stdin);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n+n;i++){
        int x;
        cin>>x;
        if(a[x].first==0)
            a[x].first=i;
        else
            a[x].second=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(  a[i].first <a[j].first && a[i].second< a[j].first  )
                continue;

            if(a[i].first<a[j].first && a[i].second>a[j].second)
                continue;

            if(  a[j].first <a[i].first && a[j].second< a[i].first  )
                continue;

            if(a[j].first<a[i].first && a[j].second>a[i].second)
                continue;

            ans++;
        }
    }
    cout<<ans<<endl;
}