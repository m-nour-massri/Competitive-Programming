
//USACO 2017 January Contest, Bronze
//Problem 2. Hoof, Paper, Scissors
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2+9;
int n,ans;
pair<int,int> a[inf];
int main(){

    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second,a[i].first--,a[i].second--;

    int id[]={0,1,2};

    do{
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=( (id[ a[i].first ] +1)%3  == id[ a[i].second ]);
        ans=max(ans,cnt);
    }while(next_permutation(id,id+3));


    cout<<ans<<endl;
}