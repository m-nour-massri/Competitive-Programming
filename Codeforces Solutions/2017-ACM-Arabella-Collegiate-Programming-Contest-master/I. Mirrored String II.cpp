#include <bits/stdc++.h>
using namespace std;
vector <char> v = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
const int inf=1e3+9;
bool dp[inf][inf];

bool check (char s){

    for(auto o:v)
        if(o==s)
            return true;
    return false;
}

string in(){
    char s[inf];
    scanf("%s",s);
    return string(s);   
}
void solve(){
    string a;
    cin>>a;
    int n=a.size();
    
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=0;i<n;i++)
        if(check(a[i]))
            dp[i][i]=1,ans=1;

    for(int i=0;i<n-1;i++)
        if(check(a[i]) && a[i]==a[i+1])
            dp[i][i+1]=1,ans=max(ans,2);

    for(int len=2;len<n;len++)
        for(int i=0;i<n-len;i++)
            if(check(a[i]) && a[i]==a[i+len] && dp[i+1][i+len-1] )
                dp[i][i+len]=1,ans=max(ans,len+1);

    printf("%d\n",ans);

}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}