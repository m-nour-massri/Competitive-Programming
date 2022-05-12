//IOI team 1.Graduation Party (confetti)

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 1e2+9;
ll n,a[inf];
set<ll> s;

int main(){

    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll gc = a[1];
    for(ll i=2;i<=n;i++)
        gc = __gcd(gc,a[i]);

    for(ll i=1;i*i <= gc;i++){
        if(gc % i)
            continue;
        s.insert(gc/i),s.insert(i);
    }
    for(auto o:s)
        cout<<o<<" ";
    cout<<endl;
}