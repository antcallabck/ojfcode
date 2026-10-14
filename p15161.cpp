#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
#define MAXN 100005
int x[MAXN];
int m[MAXN];
int main(){
	int n , q;
	cin >> n;
	for(int i = 0 ;i < n ;i++){
		cin >> x[i];
	}
	sort(x , x + n);
	cin >> q;	
	for(int i = 0 ;i < q ; i++){
		ll m ;
		cin >> m;
		int * p = upper_bound(x , x+n , m);
		cout <<  p - x<< endl;
		
	}
	return 0;
}
