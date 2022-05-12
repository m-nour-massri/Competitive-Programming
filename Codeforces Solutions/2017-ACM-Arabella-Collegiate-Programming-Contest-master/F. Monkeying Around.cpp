#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n , m ;
int cnt[N];
vector<vector<pair<int,pair<int,int> > > > pl;
vector<vector<int> > mi;
priority_queue<pair<int,pair<int,int> > > q;


int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(cnt,0,sizeof(cnt));
        pl.clear();
        mi.clear();
        while(!q.empty())
            q.pop();
        scanf("%d%d",&n,&m);
        pl.resize(n+2);
        mi.resize(n+2);
        for(int i=0;i<m;i++){
            int x,l,k;
            scanf("%d%d%d",&x,&l,&k);
            pl[max(1,x-k)].push_back(make_pair(i,make_pair(min(n,x+k),l)));
            mi[min(n,x+k)].push_back(l);

        }
        int ans = 0 ;
        for(int i=1;i<=n;i++){
            int si = pl[i].size();
            for(int j=0;j<si;j++){
                q.push(pl[i][j]);
                cnt[pl[i][j].second.second]++;
            }
            while(!q.empty() && q.top().second.first < i){
                q.pop();
            }
            if(q.empty() || cnt[q.top().second.second] >= 2){
                ans++;
            }
            si = mi[i].size();
            for(int j=0;j<si;j++){
                cnt[mi[i][j]]--;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}