//IOI 05-birthday

/*

binary search on the answer in n*log(n)

we have two choices of final permutations 1,2,3,  n and n,n-1,  1
and n shuffles for each choice

we can handle the second choice same as handling the first by after
reversing the array

so when setting binary search bounds l,r and asking if we
can get an answer less than or equal to mid
here pi is the index of value i such that a[ pi ] = i
then for each element in a we suppose that the start of the
final permutation S that satisfies the condition of abs(pi - Si) <= mid
can be between L = (pi - mid - i+1) and R =(pi +mid - i +1) inclusively
well of course those indexes may go out of the array bounds
and as the array is cyclic then we can double the array to handle
overflow cases

so we make array pre to decide a valid start of the sequence
and for each i , pre[L] ++ ,pre[R] --
as starting the sequence between L and R is valid for element i

then we sum up the array pre from 1 to n:pre[i] += pre[i-1]

then if(any pre[i] == n) then we can make such an arrangement with
a distance less than or equal to mid
and continue our binary search on the answer

*/


#include <bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int inf = 1e6+9;
int a[inf],n,pos[inf];
int pre[inf<<1];

void range(int l,int r){

        if(l>0 && r<=n*2)
            pre[l]++,pre[r+1]--;
        else if(l+n > 0 && r+n<=n*2)
            pre[l+n]++,pre[r+n+1]--;
        else
            pre[l+2*n]++,pre[r+2*n+1]--;
}

bool check(int k){
     for(int i=0;i<=n*2;i++)
        pre[i] = 0;

    for(int i=1;i<=n;i++){
        int l = pos[i] - k - (i-1);
        int r= pos[i] + k - (i-1);
        range(l,r);
    }

    for(int i=1;i<=n*2;i++)
        pre[i] += pre[i-1];

    for(int i=1;i<=n;i++)
        if( (pre[i] + pre[i+n] == n) )
            return 1;
    return 0;
}

int bs(){
    for(int i=1;i<=n;i++)
        pos[ a[i] ] = i;
        int l = -1,r = n/2+1;
    while(r-l>1){
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);

    int ans = bs();//for 1,2,3,4,   n
    reverse(a+1,a+1+n);//for n,n-1,   2,1
    printf("%d\n",min(ans,bs()));
}
