#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 根据题目可能的最大特征值调整数组大小，如果特征值更大可以适当调大
const int MAXN = 1005; 
int cnt[MAXN];

int main() {
	int n;
	cin >>n;
	int mv= 0;
	for(int i = 0 ;i < n; i ++){
		int k; 
		cin >> k;
		for(int j =0 ; j < k ; j ++){
			int v;
			cin >> v;
			cnt[v]++;
			if(v > mv){
				mv =v;
			}
		}
	}
	int mc =0;
	int mi =0;
	for(int i =0; i <= mv ;i++){
		if(cnt[i] >= mc){
			mc = cnt[i];
			mi = i;
		}
	}
	cout <<mi<<endl;
	cout <<mc<<endl;
}
