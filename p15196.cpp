#include <iostream>
#include <string>
using namespace std;
using ll = long long;
#define MAXN 200005
// dp[i][0] 前 i 天，并且第 i 天最终安排为 R 时，能够获得的最大净收益。
// dp[i][1] 前 i 天，并且第 i 天最终安排为 S 时，能够获得的最大净收益。
ll dp[MAXN][2]; 
ll x[MAXN];
ll y[MAXN];
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s= " "+s;
	for(int i =1 ;i <= n ;i ++){
		cin >> x[i];
	}
	for(int i =1 ;i < n ;i ++){
		cin >> y[i];
	}
	// 初始化第一天
	dp[1][0] = (s[1] == 'R' ? 0 : -x[1]);
	dp[1][1] = (s[1] == 'S' ? 0 : -x[1]);
	for (int i = 2; i <= n; i++) {
		// 第i天最终为R的修改代价
		ll costR = (s[i] == 'R' ? 0 : x[i]);
		
		// 第i天最终为S的修改代价
		ll costS = (s[i] == 'S' ? 0 : x[i]);
		// 第i天最终为R
		dp[i][0] = max(
					   dp[i-1][0],
					   dp[i-1][1]
					   ) - costR;
		
		// 第i天最终为S
		dp[i][1] = max(
					   dp[i-1][0] + y[i-1],
					   dp[i-1][1]
					   ) - costS;
	}
	cout << max(dp[n][0], dp[n][1]);
	return 0;
}
