#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long ;
int main(){
	int n , c;
	cin >> n>> c;
	ll a[100000];
	for(int i = 0 ;i < n ; i ++){
		cin >> a[i];
	}
	sort(a , a+ n);
	int s =0 ;
	for(int i =0 ;i < n ;i ++){
		ll t = a[i] + c;
		ll * lp = lower_bound(a, a + n, t);
		ll * rp = upper_bound(a, a + n, t);
		s = s + (rp - lp);
	}
	cout << s <<"\n";
	return 0;
}
