#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000005
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int next[MAXN];
	string p ;
	while (getline(cin, p)) {
	
		int len_p = p.length();
	
		for(int i =0 ;i < len_p ; i ++){
			next[i] = 0;
		}
		for(int i = 1, j =0 ; i < len_p ; i++){
			while(j > 0 && p[i]!=p[j]){
				j = next[j -1];
			}
			if(p[i]==p[j]){
				j++;
			}
			next[i] = j;
		}
		
		vector<int> lengths;
		int curr = next[len_p - 1];
		while (curr > 0) {
			lengths.push_back(curr);
			curr = next[curr - 1]; // 继续找更短的公共前后缀
		}
		// 别忘了字符串本身也是前缀和后缀
		lengths.push_back(len_p);
		sort(lengths.begin(), lengths.end());
		// 输出当前字符串的结果
		for (int i = 0; i < lengths.size(); i++) {
			cout << lengths[i] <<  " ";
		}
		cout << endl;
	}
	return 0;
}
