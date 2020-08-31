
/*
https://tlx.toki.id/problems/osn-2016-1/B/
subtasks: 1 - 6 , 59 points

devide the array into four equal parts of size n/4
for each part push the buttons of that part from the begginning to the end 5 times
the total is n + n/4 if a BIP appeared then the current part contains the BIP button (we push each button addition 4 parts because the k can be n-1 )
we continue pushing this part buttons till we have n BIPS
we first ask for the first part then second part then the third part if there is no BIP then the BIP button is definitely in the fourth part

so our number of pushes in the worst case is (n+n/4) * 4 + n*(n/4)
which is enough so solve the first 6 subtasks 

PS: when the bomb is from type 1 between every 2 BIPS there should be at most n pushed and it is satisfied in the abaove solution as we repeat pushing the 
current part buttons from the begginning to the end 5 times if BIP button is in that part we continue pushing that part buttons keeping the difference
from the last BIP less t than n
*/

#include <bits/stdc++.h>
using namespace std;
string s;
int n,t,R,ans = 0,Left;

bool check(int l,int r){
        if(r == n)
            return 1;
        for(int i = l,cnt = 1;cnt <= n+ (r-l+1) && Left > 0;i++,cnt++){
            if(i == r+1)
                 i = l;
            cout<<i<<endl;
            cin>>s;
            Left -= (s == "BIP");
            if(s == "BIP" && cnt > n)return 1;
        }
        return 0;
}

int main(){
    cin>>s;
    cin>>n>>t>>R;
    Left = n;
    int l = 1,r = n;
    vector<int> v = {0,n/4,n/2,3*n/4,n};

    for(int i=0;i<4;i++){
        if(check(v[i]+1,v[i+1])){
            l = v[i]+1,r = v[i+1];
            break;
        }
    }
    int i = l;
    while(Left > 0){
        if(i == r+1)
            i = l;
        cout<<i<<endl;
        cin>>s;
        Left -= (s== "BIP");
        i++;
    }
}
