#include <bits/stdc++.h>
using namespace std;
const int inf=1e5+9;
int oc[11];
int sc[11];
void solve(){
    memset(sc,0,sizeof(sc));
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    vector <int> v;
    for(int i=1;;i++){
        memset(oc,0,sizeof(oc));
        int te=a*i*i+b*i;
        if(te>n)
            break;
        while(te){
            oc[te%10]++;
            te/=10;
        }
        int mx=0;
        for(int i=0;i<10;i++)
            mx=max(mx,oc[i]);
        for(int i=0;i<10;i++)
            if(oc[i]==mx && oc[i]>0)
                sc[i]++;
    }
    int ans=0,x=-1;
    for(int i=0;i<10;i++)
        if(sc[i]>ans)
            ans=sc[i],x=i;
    printf("%d\n",x);
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
