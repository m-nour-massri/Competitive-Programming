//USACO 2017 February Contest, Gold
//Problem 3. Why Did the Cow Cross the Road III
//BIT solution
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
pair<int,int> a[inf];
int tree[inf],n,ans;

void update(int x, int val){
    for(; x <= n+n; x += x&-x)
          tree[x] += val;
}

int query(int x){
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += tree[x];
     return sum;
}

int main(){

    //freopen("circlecross.out","w",stdout);
    //freopen("circlecross.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n+n;i++){
        int x;
        cin>>x;
        if(a[x].first==0)
            a[x].first=i;
        else
            a[x].second=i;
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){

        ans+=query(a[i].second)-query(a[i].first-1);
        update(a[i].second,1);
    }


    cout<<ans<<endl;
}