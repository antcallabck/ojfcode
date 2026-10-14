#include <iostream>
using namespace std;

const int N = 100000;
const int MOD = 10007;

int dp[N + 1];

int main() {
	dp[0] = 1;
	dp[1] = 5;
	
	for (int i = 2; i <= N; i++) {
		dp[i] = (5 * dp[i - 1] + 8 * dp[i - 2]) % MOD;
	}
	
	int T;
	cin >> T;
	
	while (T--) {
		int L;
		cin >> L;
		cout << dp[L] << endl;
	}
	
	return 0;
}
