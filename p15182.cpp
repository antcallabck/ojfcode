#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long ;
#define MAXN 200005
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
ll d[MAXN];
bool cmp( ll x, ll y) {
	return x > y;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n ,k;
	cin >> n >> k;
	for(int i =0; i < n ;i++){
		cin >> a[i];
	}
	for(int i =0; i < n ;i++){
		cin >> b[i];
	}
	for(int i =0; i < n ;i++){
		cin >> c[i];
	}
	ll s =0;
	for(int i =0 ;i < n ;i++){
		d[i] = b[i] - c[i];
		s += a[i]+c[i];
	}
	sort(d ,d + n , cmp);
	
	for(int i =0 ;i < k; i++){
		s+= d[i];
	}
	cout << s;
	return 0;
	
}
