//TOKI OSN Open Contest 2019 - Day 2
//2B. Mencari Emas
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,q;

ll ask(ll x,ll y){
    ll ret;
    if ( !(x>=1 && x<=n && y>=1 && y<=m) )
        return 1e9;
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>ret;
    return ret;
}

pair<ll,ll> getpoint(ll b,ll f){
    ll x = (b+f)/2;
    return make_pair( x , b-x );
}

void out(pair<int,int> x,pair<int,int> y){
    cout<<"! "<<x.first<<" "<<x.second<<" "<<y.first<<" "<<y.second<<endl;
}

int main(){

    cin>>n>>m>>q;

    ll f1 = ask(1,m) + 1 - m , f2 = -ask(n,1) + n -1;//forward diagonal x-y
    ll b1 = ask(1,1) + 1 + 1 , b2 = -ask(n,m) + n + m;//backword diagonal x+y

    pair<int,int> point1 , point2 ;
    point1 = getpoint(b1,f1) , point2 = getpoint(b2,f2);

    if(ask( point1.first , point1.second  ) == 0)
        out(point1,point2);
    else
        point1 = getpoint(b1,f2) , point2 = getpoint(b2,f1),out(point1,point2);
}
