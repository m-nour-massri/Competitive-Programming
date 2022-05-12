

//USACO 2018 December Contest, Bronze
//Problem 3. Back and Forth
#include <bits/stdc++.h>
using namespace std;
int a[33];
set<int> s;
void bt(int first,int second,int day,int mask1,int mask2){
    if(day==5){
        s.insert(first);
        return ;
    }
    if(day%2==1){
        for(int i=0;i<20;i++){
            if( ((mask1&(1<<i))==0)  || first<a[i])
                continue;
            bt(first-a[i],second+a[i],day+1,mask1-(1<<i),(mask2|(1<<i)));
        }
    }
        else {
            for(int i=0;i<20;i++){
                if( ( (mask2&(1<<i))==0)  || second<a[i])
                    continue;
                bt(first+a[i],second-a[i],day+1,(mask1|(1<<i)) ,(mask2-(1<<i) ) );
            }
        }


}

int main(){

    freopen("backforth.out","w",stdout);
    freopen("backforth.in","r",stdin);
    for(int i=0;i<20;i++)
        cin>>a[i];
    int mask1=(1<<10)-1;
    int mask2=(1<<20)-1;
    mask2^=mask1;
    bt(1000,1000,1,mask1,mask2);
    cout<<s.size()<<endl;
}