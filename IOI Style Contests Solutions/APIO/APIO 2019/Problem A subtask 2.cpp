//Problem A subtask 2
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e6+9;
ll n,a,b,ans;
int main(){
    cin>>n>>a>>b; 
       ll x,y;
        cin>>x>>y;
        ans=0;
        ll Y=((y-x+1)>=b?b:(y-x+1)),temp=(y-x+1)/b;
        if(a<(y-x+1)/b)
            ans=Y*a;
        else
            ans=Y*temp+(y-x+1)-temp*b;
        cout<<ans<<endl;
    
}
