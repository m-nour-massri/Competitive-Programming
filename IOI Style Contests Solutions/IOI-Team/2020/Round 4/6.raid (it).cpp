//IOI Team 6.A Tantrum with Consequences (raid)

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5+9;
vector<int> out[inf];
int in[inf],n,k,a[inf],level[inf],ans;

int main(){

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i] > a[i+1])
            in[ i+1 ]++,out[i].push_back(i+1);
        else if(a[i] < a[i+1])
            in[i]++,out[i+1].push_back(i);
        else
            in[i]++,in[i+1]++,out[i+1].push_back(i),out[i].push_back(i+1);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(in[i] == 0)
            q.push(i),level[i] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(level[node] > k)
            break;
        ans++;

        for(auto o:out[node]){
            in[o]--;
            if(in[o] == 0)
                q.push(o),level[o] = level[node] + 1;
        }
    }
    cout<<ans<<endl;
}