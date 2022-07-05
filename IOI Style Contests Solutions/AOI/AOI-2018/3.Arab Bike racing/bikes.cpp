

#include <bits/stdc++.h>
using namespace std;
const int inf=2e2+9;
int a[inf],b[inf],c[inf];
int v[2][inf];
int main(){
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n+n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    n*=2;
    memset(v,-1,sizeof(v));
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if( ((1<<j)&i) !=0 )
                v[0][a[j]]=c[j];
            else v[1][b[j]]=c[j];
        }
        bool tr=1;
        int x=0,y=0;
        for(int j=0;j<n/2;j++){
            if(v[0][j]==-1 || v[1][j]==-1)
                tr=0;
            x+=v[0][j];
            y+=v[1][j];
        }
        memset(v,-1,sizeof(v));
        if(abs(x-y)<s && tr)
            cout<<"YES",exit(0);
    }
    cout<<"NO";
}
