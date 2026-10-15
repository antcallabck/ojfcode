#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n ;
	cin >> n;
	vector<int> f(n+1);
	vector<int> a(n);
	for(int i =0 ;i < n ;i ++){
		cin >> a[i];
	}
	int ans =a[0];
	f[0] = a[0];
	for(int i =1 ;i < n ;i ++){
		f[i] = max(f[i-1] + a[i], a[i]);
		ans = max(ans , f[i]);
	}
	cout << ans;
	return 0;
}
