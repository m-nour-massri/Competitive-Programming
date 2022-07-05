//TOKI OSN Open Contest 2019 - Day 2
//2A. Tourist Attraction
#include <bits/stdc++.h>
using namespace std;
const int inf=2e5+9;
int n,m,Cnt,before[inf],after[inf];
pair<pair<int,int>,int> a[inf];
map<int,int> mp;

int tree[inf+inf];
void Up(int idx){

    while(idx<=Cnt)
        tree[idx]++,idx+=idx&-idx;
}
int Qu(int x,int y){
    x--;
    int ret=0;
    while(x)
        ret-=tree[x],x-=x&-x;
    while(y)
        ret+=tree[y],y-=y&-y;
    return ret;
}

int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].first.first,&a[i].first.second),a[i].second = i,mp[ a[i].first.first ],mp[ a[i].first.second ];

    for(auto &o:mp)
        o.second=++Cnt;

    for(int i=1;i<=n;i++)
        a[i].first.first = mp[ a[i].first.first ],a[i].first.second = mp[ a[i].first.second ];
    mp.clear();
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        before[ a[i].second ] += Qu(a[i].first.first ,Cnt);
        Up(a[i].first.second );
    }

    memset(tree,0,sizeof(tree));
    for(int i=n;i>=1;i--){
        after[ a[i].second ] += Qu( 1,a[i].first.second  );
        Up(a[i].first.first );
    }

    for(int i=1;i<=n;i++)
        printf("%d\n",after[i]+before[i]);
}
