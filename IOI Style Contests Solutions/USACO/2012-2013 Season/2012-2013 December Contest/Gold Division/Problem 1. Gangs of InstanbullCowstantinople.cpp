//USACO 2012 December Contest, Gold
//Problem 1. Gangs of Instanbull/Cowstantinople
#include <bits/stdc++.h>
using namespace std;
const int inf=109;
int n,m,a[inf],ans;
multiset<int> s;
set< pair<int,int> > gangs;

void add(int &cur,int &cnt,int type,int count){

    if(cur == type)
        cnt+=count;
    else if(cur == 0)
        cur = type,cnt=count;
    else
        cnt-=count;

    if(cnt == 0)
        cur=0;
    else if(cnt<0)
        cur=type,cnt=abs(cnt);
}

int main(){

    freopen("gangs.in","r",stdin);
    freopen("gangs.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i],s.insert(a[i]);

    s.erase(s.find(a[1]));
    while(!s.empty()){
        ans=*s.rbegin();
        if(!ans)
            break;
        s.erase(s.find(ans));
        if(s.empty())
            break;
        int x=*s.rbegin();
        s.erase(s.find(x));
        ans-=x;
        s.insert(ans);
    }

    if(ans>=a[1])
        cout<<"NO\n",exit(0);
    cout<<"YES\n"<<a[1]-ans<<'\n';
    int total=a[1]-ans;
    int cur=0,cnt=0;

    for(int i=1;i<=n-total;i++){

        for(int go=1;go<=m;go++){
            if(!a[go])
                continue;
            a[go]--;
            int tcur=cur,tcnt=cnt;
            add(tcur,tcnt,go,1);

            for(int j=2;j<=m;j++)
                gangs.insert(make_pair(a[j],j));
            //we keep taking from the largest remaining gang
            while(!gangs.empty()){
                pair<int,int> x=*gangs.rbegin();
                gangs.erase(gangs.find(x));
                if(!x.first)
                    break;
                x.first--;
                add(tcur,tcnt,x.second,1);
                gangs.insert(x);
            }
            add(tcur,tcnt,1,a[1]);
            if( tcur == 1 && tcnt == total ){
                add(cur,cnt,go,1);
                cout<<go<<endl;
                break;
            }
            a[go]++;
        }
    }
    while(total--)
        cout<<1<<endl;

}