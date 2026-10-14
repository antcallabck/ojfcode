#include<iostream>
#include<algorithm>
using namespace std;
int a[30005];
int main(){
	int w , n;
	cin >> w >> n;
	for(int i = 0 ; i < n ;i++){
		cin >> a[i];
	}
	sort(a , a + n);
	int i = 0;
	int j = n - 1;
	int s = 0;
	while(i <= j){
		if(i == j){
			s ++;
			break;
		}
		if(a[i] + a [j] <= w){
			s++;
			i++;
			j--;
		}else{
			s++;
			j--;
		}
	}
	cout << s<<endl;
	return 0;
}
