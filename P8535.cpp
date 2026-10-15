#include <iostream>
using namespace std;
#define MAXN 1005
#define INF 1000000
int dp[MAXN];
int c[MAXN];
int main(){
	int n;
	cin >>n;
	for(int i =1 ;i <= n;i++){
		cin >> c[i];
	}
	dp[0] =0;
	dp[1] =0;
	
	for(int i =2 ;i <=n ;i++){	
		dp[i] = min(
					dp[i-1] + c[i],
					dp[i-2] + c[i-1]
					);
	}
	cout << dp[n];
	return 0; 
}
