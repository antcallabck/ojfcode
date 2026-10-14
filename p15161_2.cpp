#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long ;
#define MAXN 100005
int cnt[MAXN];
int main(){
	int n , q;
	cin >> n;
	memset(cnt ,0 , n);
	for(int i =0 ;i < n ;i ++){
		int x ;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 1 ; i < MAXN ;i++){
		cnt[i] = cnt[i]+ cnt[i -1];
	}
	cin>> q;
	for(int i =0 ;i < q ;i++){
		ll m;
		cin >> m;
		if (m >= 100000) {
			cout << n << endl;
		}else{
			cout << cnt[m]<<endl;
		}
	}
	return 0;
}
