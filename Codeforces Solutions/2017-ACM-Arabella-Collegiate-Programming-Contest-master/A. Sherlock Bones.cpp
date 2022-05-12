#include <bits/stdc++.h>
using namespace std;
char s[200010];
int zerol[200010];
int frq[200010];
int sum1[200010];
int sum2[200010];
int n;

long long solve(){
    memset(frq,0,sizeof(frq));
    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    long long ans = 0 ;
    int z = 0 ;
    for(int i=0;i<n;i++){
        if(s[i] == '0')
            z++;
        else{
            zerol[i] = z;
            z = 0 ;
        }
    }
    z = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '0'){
            z++;
        }
        else{
            ans+=(long long)z * (long long)zerol[i];
            z = 0 ;
        }
    }
    int sum = 0 ;
   for(int i=0;i<n;i++){
       if(s[i] == '1')
       sum++;
        frq[sum]++;
   }
   sum1[1] = frq[1];
   sum2[2] = frq[2];
   for(int i=3;i<=sum;i++){
    if(i % 2 == 1){
        sum1[i] = sum1[i-2]+frq[i];
    }
    else{
        sum2[i] = sum2[i-2]+frq[i];
    }
   }
    int nsum = 0 ;
    int last = -1 ;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            nsum++;
            if(nsum % 2 == 0){
                int esum = sum;
                if(sum % 2 != 0)
                    esum--;
                ans+=(long long)(sum2[esum]-sum2[nsum])*(long long)(i-last);
            }
            else{
                int esum = sum;
                if(sum % 2 != 1)
                    esum--;
                ans+=(long long)(sum1[esum]-sum1[nsum])*(long long)(i-last);
            }
            last = i;
        }
    }
    return ans;

}

int main()
{

	int t;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        scanf(" %s",s);
        printf("%I64d\n",solve());
	}
	return 0;
}