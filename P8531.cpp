#include <iostream>
using namespace std;
#define MAXN 105
int a[MAXN];
int dp[MAXN];//前 i 间房屋最多能够偷到多少钱

int main(){
	int n;
	cin >>n;
	for(int i =1; i<=n;i++){
		cin >> a[i];
	}
	dp[0] = 0;
	dp[1] = a[1];
	for(int i =2 ;i <= n;i++){
		dp[i]= max(dp[i-1], dp[i-2]+ a[i]);
	}
	cout << dp[n];
	return 0;
}
