//TOKI OSN Open Contest 2019 - Day 2
//2C. Hoax Spreading
#include <bits/stdc++.h>
using namespace std;
const int inf=2e5+9;
int n,S,q,cnt;
map<int,int> mp;
vector<pair<int,int> > times[inf];
vector<pair<pair<int,int>,int > > all;

int par[inf],sz[inf];
int root(int x){
    return (par[x] == x?x:par[x] = root(par[x]));
}

void join(int x,int y){
    x = root(x);
    y = root(y);
    if(x == y)
        return;
    if(sz[x]>sz[y])
        swap(x,y);
    par[x] = y;
    sz[y] += sz[x];
}

set<pair<int,int> > s;
int main(){

    scanf("%d%d%d",&n,&S,&q);
    for(int i=1;i<=n;i++){
        int tmp,x,y;
        scanf("%d",&tmp);
        while(tmp--)
            scanf("%d%d",&x,&y),times[i].push_back(make_pair(x,y)),mp[x],mp[y],all.push_back(make_pair(make_pair(x,y),i));
        par[i] = i;
        sz[i] = 1;
    }

    sort(all.begin(),all.end());
    for(auto o:all){
        while(!s.empty() && (*s.begin()).first<o.first.first )
            s.erase(s.begin());

        int mx = o.first.second;
        while(!s.empty())
            join( o.second ,  (*s.begin()).second ),mx=max(mx, (*s.begin()).first),s.erase(s.begin());

        s.insert(make_pair(mx,o.second));

    }
    while(q--){
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",sz[ root(tmp) ]);
    }
}
