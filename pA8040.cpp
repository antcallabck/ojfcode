#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int get_char_v(char v){
	switch (v) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'a':
		case 'A':
			return 10;
		case 'b':
		case 'B':
			return 11;
		case 'c':
		case 'C':
			return 12;
		case 'd':
		case 'D':
			return 13;
		case 'e':
		case 'E':
			return 14;
		case 'f':
		case 'F':
			return 15;
	}
	return 0;
}
// 自定义比较规则：按照从大到小（降序）排序
int h[256];
int s[256];
bool cmp(int a, int b) {
	if (h[a] != h[b]) {
		return h[a] > h[b];
	}
	return a < b;
}
int main(){
	int a[25][25];
	int n;
	cin >> n;
	int m;
	
	for(int i =0; i < 256 ;i ++){
		h[i] = 0 ;
		s[i] = i;
	}
	for(int i =0 ; i < n ;i ++){
		string str;
		cin >> str;
		int l = str.length();
		m = l / 2;
		for(int j  = 0; j < l ; j=j + 2){
			//TODO
			int v1 = get_char_v(str[j]);
			int v2 = get_char_v(str[j+1]);
			int v = v1 * 16 + v2;
			a[i][j / 2] = v;
			h[v] ++;
		}
	}
	sort(s , s + 256 , cmp);
	for(int i=0 ;i < 16 ;i ++){
		printf("%02X" , s[i] &0xff);
	}
	cout<<endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			int ov = a[i][j];
			int bi = 0;
			int min_diff = 999999;
			for(int k =0 ;k < 16 ; k ++){
				int diff = abs(ov - s[k]);
				if(diff < min_diff){
					min_diff = diff;
					bi = k;
				}
			}
			printf("%X", bi);
		}
		cout << endl;
	}
	return 0;
}
