#include <iostream>
#include <algorithm>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 205
using ll = long long;
ll dp[MAXN][MAXN]; //前 i 种花，恰好摆 j 盆的方案数
int a[MAXN];
#define MOD 1000007
int main(){
	if (freopen("shop.in", "r", stdin) == nullptr) {
		cerr << "Cannot open shop.in\n";
		return 1;
	}
	
	if (freopen("shop.out", "w", stdout) == nullptr) {
		cerr << "Cannot open shop.out\n";
		return 1;
	}
	int n , m;
	cin >> n >> m;
	for(int i = 1 ;i <= n ;i++){
		cin >> a[i];
	}
	dp[0][0] =1;
//	for(int i = 1; i <= n;i++){
//		for(int j =0; j <= m ; j++){
//			int ml =  min( a[i] , j);
//			for(int k =0 ;k <= ml ; k++){
//				dp[i][j] = (dp[i][j] + dp[i-1][j - k])%MOD;
//			}
//		}
//	}
	
	
	for (int i = 1; i <= n; i++) {
		// 摆0盆，始终有一种方案：所有种类都不摆
		dp[i][0] = 1;
		
		for (int j = 1; j <= m; j++) {
			// 利用左边一格的和，加上新的一项
			
//			dp[i][j-1]：
//			给每个原方案增加1盆第i种花，
//			得到“第i种至少摆1盆”的候选方案。
//			
//			dp[i-1][j]：
//			第i种一盆都不摆，
//			j盆全部由前面的种类提供。
			
			dp[i][j] =
			(dp[i][j - 1] + dp[i - 1][j]) % MOD;
			
			// 超过当前种类的数量上限，去掉多出来的一项
			if (j > a[i]) {
				dp[i][j] =
				(dp[i][j]
				 - dp[i - 1][j - a[i] - 1]
				 + MOD) % MOD;
			}
		}
	}
	cout << dp[n][m];
}
