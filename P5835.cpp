#include <iostream>
#include <string>
using namespace std;
#define MAXN 205
int dp[MAXN][MAXN];

int lsc(string & a ,string & b){
	int la = a.size();
	int lb = b.size();
	for(int i =1; i <= la ;i++){
		for(int j =1; j <= lb ;j++){
			dp[i][j] = 0;
		}
	}
	for(int i =1; i <= la ;i++){
		for(int j =1; j <= lb ;j++){
			if(a[i-1] == b[j -1]){
				dp[i][j] = dp[i-1][j-1] +1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[la][lb];
}

int main(){
	string a;
	string b;
	while(cin>>a >> b){
		cout << lsc(a, b) << endl;
	} 

	return 0;
}
