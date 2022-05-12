//USACO 2014 December Contest, Bronze
//Problem 2. Crosswords
#include <bits/stdc++.h>
using namespace std;
const int inf=55;
string a[inf];
int n,m;
bool valid(int x,int y){

    return x>=0 && x<n && y>=0 && y<m && a[x][y]=='.';
}
vector<pair<int,int> > ans;
int main(){

    freopen("crosswords.out","w",stdout);
    freopen("crosswords.in","r",stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];


    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if( (valid(i,j) && !valid(i-1,j) && valid(i+1,j) && valid(i+2,j) ) || (valid(i,j) && !valid(i,j-1) && valid(i,j+1) && valid(i,j+2))  )
                ans.push_back(make_pair(i,j));

    cout<<ans.size()<<endl;
    for(auto o:ans)
        cout<<o.first+1<<" "<<o.second+1<<endl;

}