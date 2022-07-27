#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp[12];

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        string t = "";
        for(int j=0;j<tmp.size();j++){
            t += tmp[j];
            mp[j][t]++;
        }
    }
    while(q--){
        string tmp;
        cin>>tmp;
        cout<<mp[tmp.size()-1][tmp]<<endl;
    }
}