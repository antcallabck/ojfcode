#include <iostream>
using namespace std;
#define MAXN 1005
int main(){
	int n ;
	int a[MAXN][MAXN];
	int cs[MAXN];
	int rs[MAXN];
	// 1. 初始化行列和数组
	cin >>n;
	
	for (int i = 0; i < n; ++i) {
		rs[i] = 0;
		cs[i] = 0;
	}
	for(int i =0 ;i < n ;i ++){
		for(int j =0 ; j < n ; j++){
			cin >> a[i][j];
			rs[i] = rs[i] +  a[i][j];
			cs[j] = cs[j] +  a[i][j];
		}
	}
	int m = 0;
	int e = 0;
	for(int i =0 ;i < n ;i ++){
		for(int j =0 ; j < n ; j++){
			if(a[i][j] == 0){
				e = 1;
				int v = rs[i] + cs[j];
				m = max(m , v);
			}
		}
	}
	if(e == 0){
		cout << "Bad Game!\n";
	}else{
		cout << m <<endl;
	}
	return 0;
}
