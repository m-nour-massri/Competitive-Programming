#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int arr[N] ,MaxL[N],MaxR[N],sumarr[N];
long long seg[4*N], lazy[4*N];
int n;

long long build(int s,int e,int idx){
    if(s == e)
        return seg[idx] =sumarr[s];
    return seg[idx] = build(s,(s+e)/2,idx*2)+build((s+e)/2+1,e,idx*2+1);
}


long long getsum(int s,int e,int idx,int l,int r){
    if(s > r || e < l)
        return 0;
    if(s >= l && e <= r)
    {
        if(lazy[idx] == 0){
             return seg[idx];
        }
        return (lazy[idx]*(e-s+1));
    }
    if(lazy[idx] != 0){
        lazy[idx*2] = lazy[idx];
        lazy[idx*2+1] = lazy[idx];
        seg[idx] = (lazy[idx]*(e-s+1));
        lazy[idx] = 0;
    }
    return getsum(s,(s+e)/2,idx*2,l,r) + getsum((s+e)/2+1,e,idx*2+1,l,r);
}

long long update(int s,int e,int idx,int l, int r,int val){
    if(s > r || e < l){
        if(lazy[idx] != 0){
            return lazy[idx]*(e-s+1);
        }
        return seg[idx];
    }
    if(s >= l && e <= r){
        lazy[idx] = val;
        return (val*(e-s+1));
    }
    if(lazy[idx] != 0){
        lazy[idx*2] = lazy[idx];
        lazy[idx*2+1] = lazy[idx];
        lazy[idx] = 0;
    }
    return seg[idx] = update(s,(s+e)/2,idx*2,l,r,val)+update((s+e)/2+1,e,idx*2+1,l,r,val);

}

int FindLeft(int idx,int Maxidx,int val){
    int l = Maxidx, r = idx;
    int tmp = idx;
    while(r >= l){
        int mid = (l+r)/2;
        int num = getsum(0,n-1,1,mid,mid);
        if(num <= val){
            tmp = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    return tmp;

}

int FindRight(int idx,int Maxidx,int val){
    int l = idx,r = Maxidx;
    int tmp = idx;
    while(r >= l){
        int mid = (l+r)/2;
        int num = getsum(0,n-1,1,mid,mid);
        if(num <= val){
            tmp = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    return tmp;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        memset(lazy,0,sizeof(lazy));
        int q;
        scanf("%d%d",&n,&q);
        long long allsum = 0 ;
        int Max =0, Maxidx=0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            allsum+=arr[i];
            if(arr[i] > Max){
                Max = arr[i];
                Maxidx = i;
            }
        }
        int mx = 0  ;
        for(int i=0;i<n;i++){
             MaxL[i] = mx;
             mx = max(mx,arr[i]);
        }
         mx = 0 ;
        for(int i=n-1;i>=0;i--){
            MaxR[i] = mx;
            mx = max(mx,arr[i]);
        }
        for(int i=0;i<n;i++){
            sumarr[i] = max(min(MaxR[i],MaxL[i]),arr[i]);
        }
        build(0,n-1,1);
        while(q--){
            char x;
            scanf(" %c",&x);
             if(x == 'P'){
                 printf("%I64d\n",getsum(0,n-1,1,0,n-1)-allsum);
                continue;
            }
            int idx , val;
            scanf("%d%d",&idx,&val);
            idx--;
            allsum+=val;
            val+=arr[idx];
            arr[idx] = val;
            if(idx == Maxidx){
                 update(0,n-1,1,idx,idx,val);
                Max = val;
                continue;
            }
            if(val > Max){
                update(0,n-1,1,min(idx,Maxidx),max(idx,Maxidx),Max);
                update(0,n-1,1,idx,idx,val);
                Max = val;
                Maxidx = idx;
                continue;
            }
            int num = getsum(0,n-1,1,idx,idx);
            if(num >= val)
            continue;
            if(idx > Maxidx){
                int newidx = FindLeft(idx,Maxidx,val);
                update(0,n-1,1,newidx,idx,val);
            }
            else{
                int newidx = FindRight(idx,Maxidx,val);
                update(0,n-1,1,idx,newidx,val);
            }
        }
    }
    return 0;
}