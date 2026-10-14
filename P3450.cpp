#include <iostream>
using namespace std;
using ll = long long ;
#define MAXN 10005
ll f[MAXN];
int a[MAXN];
int main(){
	// 提升标准 I/O 操作的执行效率
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	f[1] = 1;
	f[2] = 2;
	for(int i =1 ;i <= 48 ;i ++){
		f[i+2] = f[i+1] + f[i];
	}
	while(cin >> n){	
		cout << f[n] << "\n";
	}

	return 0;
}
