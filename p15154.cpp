#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;

	 string ms;
	int m = -1 ;
	for(int i =0 ;i < n; i++){
		string s;
		int d;
		cin>> s;
		cin>> d;
		if(d > m){
			m = d;
			ms = s;
		}
	}
	cout << ms;
	return 0;
}
