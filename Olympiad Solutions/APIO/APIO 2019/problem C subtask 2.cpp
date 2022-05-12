//problem C subtask 2
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=3e5+9;
int n,q;
int last[inf],ans[inf];
string state;

int main(){

    cin>>n>>q>>state;
    state=" "+state;
    for(int i=1;i<=n;i++)
        last[i]=1;

    for(int i=1;i<=q;i++){
        string type;
        int x,y;
        cin>>type>>x;
        if(type=="toggle"){
            if(state[x]=='1')
                ans[x]+=i-last[x]+1,state[x]='0',last[x]=i+1;
            else
                state[x]='1',last[x]=i+1;
        }
        else {
            cin>>y;
            if(state[x]=='1')
                cout<<ans[x]+(i-last[x]+1)<<endl;
            else
                cout<<ans[x]<<endl;
        }
    }
}
