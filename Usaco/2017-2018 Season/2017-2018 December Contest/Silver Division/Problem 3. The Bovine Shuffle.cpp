//USACO 2017 December Contest, Silver
//Problem 3. The Bovine Shuffle
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf],in[inf],n,ans;
int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);

    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
        cin>>a[i],in[a[i]]++;

    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q.push(i),ans--;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        if( --in[a[node]]==0 )
            q.push(a[node]),ans--;
    }
    cout<<ans<<endl;
}