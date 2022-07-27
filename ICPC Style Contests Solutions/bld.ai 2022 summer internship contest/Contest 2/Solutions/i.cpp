#include <bits/stdc++.h>
using namespace std;
string a,b,res = "";

int main(){
    cin>>a>>b;
    int mn = min(a.size(),b.size());
    for(int i=0;i<min(a.size(),b.size());i++){
        res += a[i];
        res += b[i];
    }
    for(int i=mn;i<a.size();i++)
        res += a[i];
    for(int i=mn;i<b.size();i++)
        res += b[i];
    cout<<res<<endl;
}