#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 1e6 + 8;
string str;
int convertToNumber(int i, int j) {
	int res = 0;
	for (; i <= j; ++i) {
		res *= 10;
		res += str[i] - '0';
	}
	return res;
}
int dp[inf];
bool sieve[inf];
void prepSieve() {
	sieve[0] = sieve[1] = true;
	for (int i = 2; i < inf; ++i) {
		if (1LL * i*i >= inf)break;
		for (int j = i * i; j < inf; j += i)
			sieve[j] = true;
	}
}
int main() {
	
	cin >> str;
	dp[0] = 1;
	prepSieve();
	int n = str.length();
	for (int i = 1; i < n; ++i) {
		int best = 1e9 + 9;
		for (int j = 0; i - j >= 0 && j < 6; ++j) {
			if (!sieve[convertToNumber(i - j, i)])
				best = min(best, 1 + (i - j ? dp[i - j - 1] : 0));
		}
		dp[i] = best;
	}
	cout << dp[n - 1] << endl;
}