//USACO 2012 December Contest, Bronze
//Problem 2. Scrambled Letters
#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int inf=5e4+9;
int n,incpos[inf],decpos[inf];
string a[inf];
pair<string,int> in[inf],de[inf];

int main(){

    freopen("scramble.in","r",stdin);
    freopen("scramble.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        in[i]=make_pair(a[i],i);
        sort(in[i].first.begin(),in[i].first.end());
        de[i]=make_pair(a[i],i);
        sort(de[i].first.begin(),de[i].first.end());
        reverse(de[i].first.begin(),de[i].first.end());
    }
    sort(in+1,in+1+n);
    sort(de+1,de+1+n);

    for(int i=1;i<=n;i++)
        incpos[ in[i].second ]=i,decpos[ de[i].second ]=i;

    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
        int l=0,r=n;
        while( r-l>1 ){
            if( de[mid].first>=a[i] )
                r=mid;
            else
                l=mid;
        }
        cout<<r<<" ";

        reverse(a[i].begin(),a[i].end());
        l=1,r=n+1;
        while(r-l>1){
            if(in[mid].first>a[i])
                r=mid;
            else
                l=mid;
        }
        cout<<l<<endl;
    }
}