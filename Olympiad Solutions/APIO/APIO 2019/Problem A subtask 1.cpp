//Problem A subtask 1
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e6+9;
set<pair<ll,ll> > s;
ll n,a,b;
int main(){
    //scanf("%I64d%I64d%I64d",&n,&a,&b);
    cin>>n>>a>>b;
    for(ll i=1;i<=n;i++){
        ll x,y;
        //scanf("%I64d%I64d",&x,&y);
        cin>>x>>y;
        for(ll j=x;j<=y;j++)
            s.insert(make_pair( (j+(ll)((ll)j/b))%a , j%b  ));
    }

    //printf("%I64d\n",(ll)s.size());
    cout<<s.size()<<endl;
}
