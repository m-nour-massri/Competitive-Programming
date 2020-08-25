
/*

        POI 14-Little_Bird
        can be solved by dynamic programming dp[i] = min( dp[j] + (a[j] <= a[i]) ): where j>= i-k
        this will be in O(n*k*q)
        we can use segment tree with coordinate compress (compress a[i] values and use them as indexes in segment tree) to reduce the time complexity to O(n * log(n) * q) which still be TLE

  we see than in range [i, i + k], MaxDp(i, i+k) - MinDp(i, i+k) <= 1, so we  use two deques to store indexes one for Minimum dp and the other fro maximum dp 
  and if the largest a[j] in the minimum deque is larger than a[i] then dp[i] = dp[j] and we add i to Minimum deque
  else dp[i] = dp[j]+1 and we add i to the maximum deque 

  whenever the minimum deque is empty we swap the two deques 
*/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6+9;
int a[inf],n,q,dp[inf];

deque<int> dq[2];

int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);

    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        dq[0].clear(),dq[1].clear();

        dp[1] = 0;
        dq[0].push_back(1);
        int Mn = 0,Mx = 1;
        for(int i=2;i<=n;i++){

            if(dq[Mn].empty())
                swap(Mn,Mx);

            if( a[i] < a[dq[Mn].back()] ){
                dp[i] = dp[ dq[Mn].back() ];
                while( !dq[Mn].empty() && a[dq[Mn].front()] <= a[i]  )
                    dq[Mn].pop_front();
                dq[Mn].push_front(i);
            }
            else {
                dp[i] = dp[ dq[Mn].back() ] + 1;
                 while( !dq[Mx].empty() && a[dq[Mx].front()] <= a[i]  )
                    dq[Mx].pop_front();
                dq[Mx].push_front(i);
            }
            if(!dq[Mn].empty() && dq[Mn].back() <= i-k)
                dq[Mn].pop_back();

            if(!dq[Mx].empty() && dq[Mx].back() <= i-k)
                dq[Mx].pop_back();
        }

        printf("%d\n",dp[n]);
    }
}
