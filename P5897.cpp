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
	f[3] = 4;
	for(int i =1 ;i <= 30 ;i ++){
		f[i+3] = f[i+2] + f[i+1] + f[i];
	}
	while(cin >> n){	
		if(n ==0) break;
		cout << f[n] << "\n";
	}
	
	return 0;
}
