#include <iostream>
using namespace std;
#define MAXN 1005
int a[MAXN];
int dp[MAXN];//表示以第 i 个数结尾的最长上升子序列长度。每个数单独都能构成长度为 1 的子序列，因此初始值为 1
int main(){
	int n ;
	cin >> n;
	for(int i = 1;i <= n ;i++){
		cin >> a[i];
	}
	int ans =0;
	for(int i =1 ;i <= n ;i++){
		dp[i] = 1;
		for(int j = 1; j <= n ;j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i] , dp[j] + 1);
			}
		}
		ans = max(ans , dp[i]);
	}
	cout << ans;
	return 0;
}
