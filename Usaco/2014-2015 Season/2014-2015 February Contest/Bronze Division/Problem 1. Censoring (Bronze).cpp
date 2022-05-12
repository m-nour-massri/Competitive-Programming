//USACO 2015 February Contest, Bronze
//Problem 1. Censoring (Bronze)
#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("censor.in","r",stdin);freopen("censor.out","w",stdout);

    string s,t,ans="";
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        ans+=s[i];
        int x=t.size();
        if(ans.size()>=t.size() && ans.substr(ans.size()-t.size(),t.size())==t  )
            while(x--)
                ans.erase(ans.size()-1);
    }
    cout<<ans<<endl;
}
