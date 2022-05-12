#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 2e5 + 9;
typedef long long ll;
#define le x+x
#define ri x+x+1
#define mid (l+r)/2
int timer = 0;
int beg[inf];
int en[inf];
vector<int>adj[inf];
ll sgt[inf << 2];
void dfs(int x, int p) {
	beg[x] = timer++;
	for (auto &k : adj[x]) {
		if (k != p)
			dfs(k, x);
	}
	en[x] = timer - 1;
}
int s, e, v;
void update(int x, int l, int r) {
	if (s <= l && e >= r) {
		sgt[x] += v;
		return;
	}
	if (mid >= s)
		update(le, l, mid);
	if (mid + 1 <= e)
		update(ri, mid + 1, r);
}
ll query(int x, int l, int r) {
	if (l == r)
		return sgt[x];
	if (mid >= s)
		return sgt[x] + query(le, l, mid);
	return sgt[x] + query(ri, mid + 1, r);
}
int source[inf];
ll accVal[inf];
int main() {
	int n, m, q;
	int a, b, c;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		source[i] = a - 1;//-1
	}
	for (int i = 1; i < m; ++i) {
		scanf("%d", &a);
		--a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}
	dfs(0, -1);
	while (q--) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d%d", &b, &v);
			--b;
			s = beg[b];
			e = en[b];
			if (s > e)exit(-1);
			update(1, 0, m - 1);
		}
		else if (a == 2) {
			scanf("%d%d", &b,&c);	
			--b;
			--c;
			int reg = source[b];
			s = beg[reg];
			ll res=query(1, 0, m - 1);
			accVal[b] += res;
			// determine the amount in the transfered one
			s = beg[c];
			res = query(1, 0, m - 1);
			accVal[b] -= res;
			source[b] = c;
		}
		else if (a == 3) {
			scanf("%d", &b);
			--b;
			int reg = source[b];
			s = beg[reg];
			ll res = query(1, 0, m - 1);
			printf("%lld\n", accVal[b] + res);
		}
	}
}
