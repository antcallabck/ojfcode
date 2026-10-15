#include <iostream>
using namespace std;
#define MAXN 100005
int dp[MAXN]; //从第 i 个弹簧板开始，到弹出去需要的弹跳次数
int a[MAXN];
int main(){
	int n;
	cin >> n;
	for(int i =1 ;i <= n ;i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = n ;i >=1 ;i --){
		int next =i +a[i];
		if(next > n){
			dp[i] = 1;
		}else{
			dp[i] = dp[next] +1;
		}
		ans = max(ans , dp[i]);
	}
	cout << ans;
	
	return 0;
}
