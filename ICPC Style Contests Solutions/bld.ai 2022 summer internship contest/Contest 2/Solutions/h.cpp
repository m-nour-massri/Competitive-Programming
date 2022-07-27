#include <bits/stdc++.h>
#define int long long
using namespace std;
int h;

int getlargestbit(int x){
    int ret = 0;
    while(x % 2 == 0)
        x/=2ll,ret++;
    return ret;
}

struct Node{
    int val,level,idx;
    void calc0(){

        level = h - getlargestbit(val);
        idx = (val/(1ll<<(h-level)) + 1ll)/2ll;
    }
    void up(){
        level--;
        idx = (idx+1ll)/2ll;
        val = (1ll<<(h-level))*(2ll*idx-1ll);
    }
}a,b;


void solve(){
    cin>>h>>a.val>>b.val;
    a.calc0();
    b.calc0();

    while(a.level > b.level)
        a.up();
    while(b.level > a.level)
        b.up();
    while(a.val != b.val)
        a.up(),b.up();
    cout<<a.val<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}