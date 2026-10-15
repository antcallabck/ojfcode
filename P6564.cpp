#include <iostream>
using namespace std;
#define MAXN 100005
int a[MAXN];
int dp[MAXN];//以数字 i 结尾，且在原排列中位置递增的最长连续数值段的长度。
int main(){
	int n;
	cin >> n;
	for(int i =1;i <= n;i++){
		int x;
		cin >>x;
		a[x] = i;
	}
	dp[1] =1;
	int m = 1;
	for(int i = 2 ;i <= n;i++){
		if(a[i -1] < a[i]){
			dp[i] = dp[i-1]+1;
		}else{
			dp[i] = 1;
		}
		m = max(m,dp[i]);
	}
	cout << n -m;
	return 0;
}
