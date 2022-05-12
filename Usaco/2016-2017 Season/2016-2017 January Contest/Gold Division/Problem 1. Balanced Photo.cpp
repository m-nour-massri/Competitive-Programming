//USACO 2017 January Contest, Gold
//Problem 1. Balanced Photo
#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int a[inf],le[inf],ri[inf],n,cnt;
map<int,int> mp;
void update_left(int x,int val){

    while(x<=n)
        le[x]+=val,x+=x&-x;

}

int query_left(int x){

    int ans=0;
    while(x)
        ans+=le[x],x-=x&-x;

    return ans;
}

void update_right(int x,int val){

    while(x<=n)
        ri[x]+=val,x+=x&-x;
}

int query_right(int x){
    int ans=0;
    while(x)
        ans+=ri[x],x-=x&-x;

    return ans;
}

int main(){

    freopen("bphoto.out","w",stdout);
    freopen("bphoto.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),mp[a[i]];

    for(auto &o:mp)
        o.second=++cnt;

    for(int i=1;i<=n;i++)
        update_right(mp[a[i]],1);

    int ans=0;
    for(int i=1;i<=n;i++){
        update_right(mp[a[i]],-1);

        int l=query_left(cnt)-query_left(mp[a[i]]),r=query_right(cnt)-query_right(mp[a[i]]);

        ans+=(min(l,r)*2<max(l,r));
        update_left(mp[a[i]],1);
    }
    printf("%d\n",ans);
}