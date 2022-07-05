#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf =1e5+9;
int a,b;

signed main(){
    ios::sync_with_stdio(0);
    cin>>a>>b;
    if(a>b)
        swap(a,b);

    a = a*(a-1)/2;
    b = b*(b+1)/2 - a;
    cout<<(b%2 == 0?"Nasser":"Hoss")<<endl;
}

