

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x,m,y,ans;

int getKth(int k){

    int l = 1, r = 1e17,ret = 0;
    while(l<r){
        int mid = (l+r)/2;
        int tmp = min(n,mid/x) + min(m,mid/y);
        if(tmp >= k)
            ret = mid,r = mid;
        else
            l = mid+1;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin>>n>>x>>m>>y;
    if( (n+m)%2 == 1 )
        cout<<fixed<<setprecision(1)<<1.0*getKth((n+m+1)/2)<<endl;
    else
        cout<<fixed<<setprecision(1)<<1.0*(getKth((n+m)/2)+getKth((n+m)/2+1))/2.0<<endl;
}
