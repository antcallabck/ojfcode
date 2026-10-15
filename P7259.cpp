#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define MAXN 105
int a[MAXN][MAXN];
int dp[MAXN][MAXN];//以位置 (i,j) 为右下角，能够组成的最大全 1 正方形的边长
int main(){
	int n , m;
	cin >> n >> m;
	for(int i =1;i <=n;i++){
		for(int j =1;j <=n;j++){
			cin>>a[i][j];
		}
	}
	int ans = 0;
	for(int i =1;i <=n;i++){
		for(int j =1;j <=n;j++){
			if(a[i][j] == 1){
				int m = 1000000;
				if(dp[i-1][j] < m){
					m = dp[i-1][j];
				}
				if(dp[i][j-1] < m){
					m = dp[i][j-1];
				}
				if(dp[i-1][j-1] < m){
					m = dp[i-1][j-1];
				}
				dp[i][j] = m +1;
			}else{
				dp[i][j] = 0;
			}
			ans = max(ans , dp[i][j]);
		}
	}
	cout << ans;
	
	return 0;
}
