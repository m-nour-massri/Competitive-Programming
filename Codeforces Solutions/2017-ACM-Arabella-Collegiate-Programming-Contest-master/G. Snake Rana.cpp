#include <bits/stdc++.h>
using namespace std;
const int inf=22;
pair<int,int> a[inf];
int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++)
            cin>>a[i].first>>a[i].second;

        long long ans=n*(n+1ll)*m*(m+1ll);
        ans/=4ll;

        for(int i=1;i<(1<<k);i++){
            int cnt=0,mxx=-1,mxy=-1,mnx=1e9+9,mny=1e9+9;
            for(int j=0;j<k;j++){
                if( (i&(1<<j)) ==0)
                    continue;
                mxx=max(mxx,a[j].first);
                mxy=max(mxy,a[j].second);
                mnx=min(mnx,a[j].first);
                mny=min(mny,a[j].second);
                cnt++;
            }
            long long te=mnx*mny*(n-mxx+1ll)*(m-mxy+1ll);
            if(cnt%2)
                ans-=te;
            else ans+=te;
        }
        cout<<ans<<endl;
    }
}