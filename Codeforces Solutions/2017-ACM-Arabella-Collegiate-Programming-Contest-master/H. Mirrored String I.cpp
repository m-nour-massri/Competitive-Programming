#include <bits/stdc++.h>
using namespace std;
vector <char> v = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
void solve(){
    string a;
    cin>>a;
    for(int i=0;i<=a.size()/2;i++){
        bool tr=1;
        for(auto o:v)
            if(o==a[i])
                tr=0;
        if(a[i]!=a[a.size()-i-1] || tr==1){
            printf("no\n");
            return ;
        }
    }
    printf("yes\n");
    return ;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}