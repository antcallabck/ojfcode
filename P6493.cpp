#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long ;
#define MAXN 1000005
ll a[MAXN];
ll b[MAXN];
ll dp[MAXN];

int main(){
	int n;
	cin >>n;
	for(int i =0 ;i < n ;i ++){
		cin >> a[i] >> b[i];
	}
	dp[n] =0;
	for(int i = n -1; i >=0 ;i --){
		ll no = dp[i+1];
		int ni ;
		if(n > i + b[i] + 1){
			ni = i + b[i] + 1;
		}else{
			ni = n;
		}
		ll yes = a[i] + dp[ni];
		dp[i] = max(yes, no);
	}
	cout << dp[0];
	return 0;
}
