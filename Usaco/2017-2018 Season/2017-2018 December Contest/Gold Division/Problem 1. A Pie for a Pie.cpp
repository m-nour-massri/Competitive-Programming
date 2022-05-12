//USACO 2017 December Contest, Gold
//Problem 1. A Pie for a Pie
#include <bits/stdc++.h>
using namespace std;
const int inf = 2e5+9;
int n,k,dis[inf],a[inf],b[inf];
queue<int> q;

struct cmpA{
    bool operator()(int x,int y){
        return b[x]>b[y];
    }
};
struct cmpB{
    bool operator()(int x,int y){
        return a[x]>a[y];
    }
};

multiset<int,cmpA > sA;//contains As from the first N cows
multiset<int , cmpB> sB;//contains Bs from the second N cows
multiset<int , cmpA> ::iterator itA;
multiset<int , cmpB> ::iterator itB;

int main(){

    freopen("piepie.in","r",stdin);
    freopen("piepie.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++)
        dis[i]=dis[i+n] = -1;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(b[i] == 0)
            q.push(i),dis[i] = 1;
        else
            sA.insert(i);
    }
    for(int i=n+1;i<=n+n;i++){
        cin>>a[i]>>b[i];
        if( a[i] == 0 )
            q.push(i),dis[i] = 1;
        else
            sB.insert(i);
    }

    while(!q.empty()){
        int i = q.front();
        q.pop();
        while(i<=n){
            itB = sB.lower_bound(i);
            if( itB == sB.end() || a[*itB]+k < a[i])
                break;
            dis[*itB] = dis[i] + 1;
            q.push(*itB);
            sB.erase(itB);
        }
        while(i>n){
            itA = sA.lower_bound(i);
            if( itA == sA.end() || b[*itA]+k < b[i] )
                break;
            dis[*itA] = dis[i] +1;
            q.push(*itA);
            sA.erase(itA);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<endl;
}