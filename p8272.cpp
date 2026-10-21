
#include <iostream>
using namespace std;
using ll = long long;
#define N  1005
ll a[N];
ll L[N][N], R[N][N];

// 封装状态转移
ll calc(ll x, ll l, ll r) {
	if (x == r) {
		return 0;
	}
	if (l <= x && x < r) {
		return x + 1;
	}
	if (r < x && x <= l) {
		return x - 1;
	}
	return x;
}
int solve(int n){
	for (int i = 1; i <= n; i++) {
		// 区间长度为 1
		L[i][i] = a[i];
		R[i][i] = a[i];
	}
	// 枚举区间长度
	for (int len = 2; len <= n; len++) {
		// 枚举区间左端点
		for (int i = 1; i + len - 1 <= n; i++) {		
			int j = i + len - 1;
			// 计算左边需要补多少石子
			L[i][j] = calc(
						   a[j],
						   L[i][j - 1],
						   R[i][j - 1]
						   );
			
			// 计算右边需要补多少石子
			R[i][j] = calc(
						   a[i],
						   R[i + 1][j],
						   L[i + 1][j]
						   );
		}
	}
	return (L[2][n] == a[1] ? 0 : 1);
}

int main() {
	int T;
	cin >> T;
	
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];			
		}
		// 只有一堆，先手必胜
		if (n == 1) {
			cout << 1 << '\n';
		} else {
			// 等于必败局面要求的数量，则先手必败
			cout << solve(n) << '\n';
		}
	}
	return 0;
}

