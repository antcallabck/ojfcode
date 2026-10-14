#include <iostream>
using namespace std;
int main(){
	int a[6];
	for(int i =0 ; i < 6 ;i ++){
		cin >> a[i];
	}
	for(int i =0 ;i  < 6 ;i++){
		for(int j = 0  ;j < 6 ;j++){
			if(j == 5){
				cout << a[(j+5-i)%6]<<endl;
			}else{
				cout << a[(j+5-i)%6] << " ";
			}
		}
	}
	return 0;
}
