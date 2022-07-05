
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf =1e5+9;
int n,a[inf];
vector<int> st;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

        for(int i=1;i<=n;i++){
            if(!st.empty() && st.back() == a[i])
                st.pop_back();
            else st.push_back(a[i]);
        }
        cout<<(int)st.size()<<endl;
        for(auto o:st)
            cout<<o<<" ";
        cout<<endl;
}
