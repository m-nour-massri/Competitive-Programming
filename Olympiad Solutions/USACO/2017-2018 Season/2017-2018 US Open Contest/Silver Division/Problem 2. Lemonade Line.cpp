//USACO 2018 US Open Contest, Silver
//Problem 2. Lemonade Line
#include <bits/stdc++.h>
using namespace std;
int don=0;
vector<int> v;
int main(){
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>=n)
            don++;
        else v.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        if(v[i]<don)
            break;
        else don++;
    cout<<don<<endl;
}