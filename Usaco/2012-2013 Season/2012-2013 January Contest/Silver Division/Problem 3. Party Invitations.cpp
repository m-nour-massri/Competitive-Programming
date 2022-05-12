
//USACO 2013 January Contest, Silver
//Problem 3. Party Invitations
#include <bits/stdc++.h>
using namespace std;
const int inf=1e6+9;
int n,m,ans;
queue<int> q;
bool vis[inf];
set<int> groups[inf],indexes[inf];
//groups [i] contains the elements of the group i
//indexes [i] contains the indexes of groups that contain cow i
int main(){

    freopen("invite.in","r",stdin);
    freopen("invite.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int sz,temp;
        cin>>sz;
        while(sz--)
            cin>>temp,groups[i].insert(temp),indexes[temp].insert(i);
    }
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(vis[cur])
            continue;
        vis[cur]=1;
        ans++;
        for(auto o:indexes[cur])
            groups[o].erase(cur);

        for(auto o:indexes[cur])
            if(groups[o].size()==1)
                q.push(*groups[o].begin());
    }
    cout<<ans<<endl;
}