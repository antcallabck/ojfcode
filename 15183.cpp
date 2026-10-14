#include <iostream>
#include <string>
using namespace std;
#define MAXN 4000005
int h[MAXN];
int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int offset = n;
	int sum = 0;
	int m = 0;
	for(int i =0 ;i < 2*n ;i++){
		h[i] = -2;
	}
	h[offset] = -1;
	
	for(int i =0 ;i < n ;i ++){
		if (s[i] == 'l') {
			sum += 1;
		} else {
			sum -= 1;
		}
		int idx =  sum + offset;
		if(h[idx] != -2){
			int len = i - h[idx];
			m = max(m , len);
		}else {
			h[idx] = i;
		}
	}
	cout << m;
	return 0;
}
