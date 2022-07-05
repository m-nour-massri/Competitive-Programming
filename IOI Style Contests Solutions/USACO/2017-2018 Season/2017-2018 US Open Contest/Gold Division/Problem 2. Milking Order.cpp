//USACO 2018 US Open Contest, Gold
//Problem 2. Milking Order
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int inf=1e5+9;
int n,m,te,x,in[inf];
vector<int> edges[inf/2],out[inf],ans;

bool check(int s){
    for(int i=1;i<=n;i++)
        out[i].clear(),in[i]=0;
    queue<int> q;
    for(int i=1;i<=s;i++){
        for(int j=1;j<edges[i].size();j++){
            te=edges[i][j];
            in[te]++;
            out[edges[i][j-1]].push_back(te);
        }
    }

    int vis=0;
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q.push(i);


    while(1){
        if(q.empty())
            if(vis!=n)
                return 0;
            else return 1;
        te=q.front();
        q.pop();
        vis++;
        for(auto o:out[te]){
            in[o]--;
            if(in[o]==0)
                q.push(o);
        }
    }

}

void gen(int s){
    for(int i=1;i<=n;i++)
        out[i].clear(),in[i]=0;
    set<int> qu;
    for(int i=1;i<=s;i++){
        for(int j=1;j<edges[i].size();j++){
            te=edges[i][j];
            in[te]++;
            out[edges[i][j-1]].push_back(te);
        }
    }
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            qu.insert(i);

    while(qu.empty()==0){
        te=*qu.begin();
        qu.erase(qu.begin());
        ans.push_back(te);
        for(auto o:out[te]){
            in[o]--;
            if(in[o]==0)
                qu.insert(o);
        }
    }
}

int main(){
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        while(x--)
            cin>>te,edges[i].push_back(te);
    }

    int l=0,r=m+1;
    while(r-l>1){
        if(check(mid))
            l=mid;
        else r=mid;
    }
    gen(l);
    cout<<ans[0];
    for(int i=1;i<ans.size();i++)
        cout<<" "<<ans[i];
    cout<<endl;
}