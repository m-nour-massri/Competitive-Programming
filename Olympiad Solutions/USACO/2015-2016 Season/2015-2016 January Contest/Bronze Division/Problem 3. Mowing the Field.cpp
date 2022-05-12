//USACO 2016 January Contest, Bronze
//Problem 3. Mowing the Field
#include <bits/stdc++.h>
using namespace std;
const int inf=1e2;
int val[inf],n;
char ty[inf];
map<pair<int,int> ,int> mp;

int main(){

    freopen("mowing.out","w",stdout);
    freopen("mowing.in","r",stdin);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ty[i]>>val[i];

        int ti=1,l=1,r=1,ans=1e9+9,b=0;

        for(int i=1;i<=n;i++){
            int adx,ady;
            if(ty[i]=='W')
                adx=0,ady=-1;
            else if(ty[i]=='N')
                adx=-1,ady=0;
            else if(ty[i]=='E')
                adx=0,ady=1;
            else
                adx=1,ady=0;

            int te=val[i];
            while(te--){
                l+=adx,r+=ady;
                if(mp.find(make_pair(l,r))!=mp.end())
                    b=1,ans=min(ans,ti-mp[make_pair(l,r)]);

                mp[make_pair(l,r)]=ti++;
            }
        }
    if(ans>1e9)
        ans=-1;
    cout<<ans<<endl;
}