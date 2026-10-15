#include <iostream>
using namespace std;
using ll = long long ;
#define MAXN 100005
ll dp[MAXN];//从位置 i 出发，到达位置 n 能获得的最大分数
ll a[MAXN];
int t[MAXN];
int main(){
	int n;
	cin >> n;
	for(int i=1; i  <= n; i++){
		cin >>a[i];
	}
	for(int i=1; i <= n -1 ;i++){
		cin >> t[i];
	}
	dp[n] = a[n];
	for(int i = n -1; i >= 1; i--){
		dp[i] = a[i] + max(dp[i+1] , dp[t[i]]);
	}
	cout << dp[1];
	return 0;
}

