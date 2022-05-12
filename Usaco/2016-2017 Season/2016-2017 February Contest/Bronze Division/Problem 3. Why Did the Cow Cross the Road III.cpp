//USACO 2017 February Contest, Bronze
//Problem 3. Why Did the Cow Cross the Road III
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int n,ans;
pair<int,int> a[inf];

int main(){

    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;

    sort(a+1,a+1+n);
    int time=0;
    for(int i=1;i<=n;i++){
        if(time>=a[i].first)
           time+=a[i].second;
        else
            time=a[i].first+a[i].second;
    }
    cout<<time<<endl;
}