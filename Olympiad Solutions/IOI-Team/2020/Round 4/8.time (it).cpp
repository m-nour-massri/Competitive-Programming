
//IOI team 8.Late for Work (time)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    if(h2 < h1 || (h1 == h2 && m1 > m2))
        h2 += 24;
    int h = h2 - h1 - ( m2 < m1 );
    int m = m2 - m1 + 60*(m2 < m1);
    cout<<h<<" "<<m<<endl;
}
