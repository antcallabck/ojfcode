#include <iostream>
#include <string>
using namespace std;
#define MAXN 105
int dp[MAXN][MAXN];
int main(){
	string a;
	string b;
	cin >> a >> b;
	int la = a.size();
	int lb = b.size();
	for(int i =1; i <= la ;i++){
		for(int j =1; j <= lb ;j++){
			if(a[i-1] == b[j -1]){
				dp[i][j] = dp[i-1][j-1] +1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	cout << dp[la][lb];
	return 0;
}
