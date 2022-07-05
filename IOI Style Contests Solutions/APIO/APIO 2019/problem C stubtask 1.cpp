
//problem C stubtask 1
#include <bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
#define le node+node
#define ri node+node+1
using namespace std;
const ll inf=109;
int n,q;
int x[inf],y[inf],ans[inf];
string state,type[inf];

int main(){

    cin>>n>>q>>state;
    state=" "+state;

    for(int i=1;i<=q;i++){
        cin>>type[i]>>x[i];
        if(type[i]=="query")
            cin>>y[i];
    }

    for(int i=1;i<=q;i++){
        for(int j=1;j<=q;j++){
            if(type[j]=="toggle")
                continue;
            int tr=1;
            for(int z=x[j];z<y[j];z++)
                if(state[z]=='0')
                tr=0;
            ans[j]+=tr;
        }

        if(type[i]=="query")
            cout<<ans[i]<<endl;

        else {
            if(state[x[i]]=='1')
                state[x[i]]='0';
            else
                state[x[i]]='1';
        }
    }
}
