#include <iostream>
using namespace std;
#define MAXN 25
int a[MAXN];
int main(){
	int n;
	cin >>n;
	for(int i =1 ;i <= n ;i ++){
		cin >> a[i];
	}
	for(int i =1 ;i <= n ;i ++){
		cout << a[i]<<" ";
		if(2 *i <= n){
			cout << a[2*i]<<" ";
		}else{
			cout << -1<<" ";
		}
		if(2 *i +1 <= n){
			cout << a[2*i+1]<<endl;
		}else{
			cout << -1<<endl;
		}
	}
	return 0;
}
