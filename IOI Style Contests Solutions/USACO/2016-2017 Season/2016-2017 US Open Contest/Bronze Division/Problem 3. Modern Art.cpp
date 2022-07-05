//USACO 2017 US Open Contest, Bronze
//Problem 3. Modern Art
#include <bits/stdc++.h>
using namespace std;
const int inf=12;
struct R{
    int x1,y1,x2,y2;
}rect[inf];
int n;
int a[inf][inf];
set<int> s,ans;
vector<int> v;

int main(){

    freopen("art.in","r",stdin);
    freopen("art.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=1;j<=n;j++){
            a[i][j] = tmp[j-1]-'0';
            if(a[i][j])
                s.insert(a[i][j]);
            int cur=a[i][j];
            if(rect[cur].x1 == 0)
                rect[cur].x1=rect[cur].x2 = i ,rect[cur].y1=rect[cur].y2=j;
            else
                rect[cur].x1=min(rect[cur].x1,i),rect[cur].x2=max(rect[cur].x2,i),
                rect[cur].y1=min(rect[cur].y1,j),rect[cur].y2=max(rect[cur].y2,j);
        }
    }
    for(auto o:s)
        v.push_back(o);

    do{
        int cur[inf][inf]={0},tr=1;
            for(auto o:v)
                for(int i=rect[o].x1;i<=rect[o].x2;i++)
                    for(int j=rect[o].y1;j<=rect[o].y2;j++)
                        cur[i][j] = o;
              for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(a[i][j] != cur[i][j])
                        tr=0;
              if(tr)
                ans.insert(v[0]);
    }while(next_permutation(v.begin(),v.end()));

    cout<<ans.size()<<endl;
}