//USACO 2017 January Contest, Silver
//Problem 3. Secret Cow Code
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char solve(string s,ll idx){

    if(idx<s.size())
        return s[idx];

    ll n = s.size();
    while( n*2ll <=idx )
        n*=2ll;
    if( n == idx )
        return solve(s,n - 1);//-1 because we shuffle the string one character
    else
        return solve(s , idx-n-1);//-1 because we shuffle the string one character
}

int main(){

    freopen("cowcode.in","r",stdin);
    freopen("cowcode.out","w",stdout);

    string s;
    ll k;
    cin>>s>>k;
    k--;
    cout<<solve(s,k)<<endl;
}