//APIO 2014 Problem 1. Palindromes
//1-2 subtasks solution 23 points
#include <bits/stdc++.h>
using namespace std;
const int inf=2e3+9;
int n,ans;
string s;
int pal[inf][inf];
map<string,int> mp;

int main(){

    cin>>s;
    n=s.size();
    s=" "+s;

    for(int i=1;i<=n;i++)
        pal[i][i]=1,pal[i][i+1]=(i<n && s[i]==s[i+1]);

    for(int len=3;len<=n;len++)
        for(int i=1;i<=n-len+1;i++)
            pal[i][i+len-1]=(pal[i+1][i+len-2] & s[i]==s[i+len-1]);

    for(int i=1;i<=n;i++){
        string temp="";
        for(int j=i;j<=n;j++){
            temp+=s[j];
            if(pal[i][j])
               mp[temp]++,ans=max(ans,mp[temp]*(j-i+1));
        }
    }
    cout<<ans<<endl;
}