#include <iostream>
#include <string>
using namespace std;
int main(){
	int n , m;
	cin >> n >> m;
	int r , c;
	cin >> r >> c;
	string seq;
	cin >> seq;

	for(int i=0 ;i  < m ;i ++){
		int x = r; 
		int y = c;
		int ans = 0;
		for(int j = i ; j < m; j++){
			int nx = x;
			int ny = y;
			if (seq[j] == 'L') ny--;
			if (seq[j] == 'R') ny++;
			if (seq[j] == 'U') nx--;
			if (seq[j] == 'D') nx++;

			if (nx < 0 || nx >= n ||
				ny < 0 || ny >= n) {
				break;
			}

			x = nx;
			y = ny;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
