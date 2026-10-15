#include <iostream>
using namespace std;
#define MAXN 1005
int a[MAXN];
int dp[MAXN];//表示以第 i 个数结尾的上升子序列的最大和
int main(){
	int n ;
	cin >> n;
	for(int i = 1;i <= n ;i++){
		cin >> a[i];
	}
	int ans =0;
	for(int i =1 ;i <= n ;i++){
		dp[i] = a[i];
		for(int j = 1; j <= n ;j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i] , dp[j] + a[i]);
			}
		}
		ans = max(ans , dp[i]);
	}
	cout << ans;
	return 0;
}
