#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 25
int a[MAXN][MAXN];
int v[MAXN][MAXN];
struct point{
	int row;
	int col;
};
struct point match[MAXN][MAXN];
// 上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n , m;
bool dfs(int x, int y) {
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];		
		// 超出矩阵范围
		if (nx < 1 || nx > n || ny < 1 || ny > m) {
			continue;
		}		
		// 不能选，或者本次已经尝试过
		if (a[nx][ny] == 0 || v[nx][ny]) {
			continue;
		}
		point old = match[nx][ny];
		v[nx][ny] = true;

		// 情况一：这个白格子还没有配对
		if (old.row == 0) {
			match[nx][ny] = {x, y};
			return true;
		}
		
		// 情况二：这个白格子已经配给别的黑格子
		// 先尝试让原来的黑格子换一个对象
		if (dfs(old.row, old.col)) {
			match[nx][ny] = {x, y};
			return true;
		}
	}
	
	return false;
}
int main(){

	cin >> n >> m;
	int total = 0 ;
	for(int i =1 ; i <= n ;i++){
		for(int j =1 ; j <= m ;j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				total ++;
			}
		}
	}
	int matching = 0;
	for(int i =1 ; i <= n ;i++){
		for(int j =1 ; j <= m ;j++){
			// 只从可选的黑格子开始寻找配对
			if (a[i][j] == 1 && (i + j) % 2 == 0) {
				// 新一轮寻找，清空访问标记
				memset(v, 0, sizeof(v));
				if (dfs(i, j)) {
					matching++;
				}
			}
		}
	}
	cout << total - matching << '\n';
	return 0;
}
