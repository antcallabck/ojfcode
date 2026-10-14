#include <iostream>
using namespace std;
using ll = long long ;

#define MAXN 55
int  b[MAXN];
ll   dp[MAXN];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i =0 ;i < m ;i ++){
		int index ;
		cin >> index;
		b[index] = 1;
	}
	dp[0] = 1;
	for(int i = 1; i <= n ;i ++){
		if(b[i] == 1){
			dp[i] = 0;
			continue;
		}
		if(i >=1){
			dp[i] = dp[i] + dp[i -1];
		}
		if(i >=2){
			dp[i] = dp[i] + dp[i -2];
		}
		if(i >=3){
			dp[i] = dp[i] + dp[i -3];
		}
	}
	cout << dp[n];
	
	return 0;
}
