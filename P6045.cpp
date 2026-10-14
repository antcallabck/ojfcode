#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
// 模数 2^31
const ll MOD = 1LL << 31;
#define MAXN 55
ll f[MAXN];
int main(){
	int n;
	cin >>n;
	f[1]= 1;
	f[2]= 1;
	for(int i = 3; i <= n ;i++ ){
		f[i] = f[i -1] + f[i -2];
	}
	ll v = f[n] %MOD;
	cout << v <<"=";
	vector<ll> a;
	for(int i = 2;i * i < v ;i++){
		while(v%i ==0){
			a.push_back(i);
			v = v / i;
		}
	}
	if(v > 1){
		a.push_back(v);
	}
	for(int i=0 ;i < a.size() ;i ++){
		if(i != a.size() -1){
			cout << a[i] << "*";
		}else{
			cout << a[i];
		}	
	}
	return 0;
}
