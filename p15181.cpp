#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long x, n;
	if (!(cin >> x >> n)) return 0;
	
	long long a[7];
	long long e[7];
	int c = 0;
	
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		if (a[i] == x) {
			e[c] = i + 1; // 记录第几次出现对应的具体天数 (1 ~ 7)
			c++;
		}
	}
	
	// 转换成 0-based 索引
	long long d = (n - 1) / c;
	long long f = (n - 1) % c;
	
	// 总天数 = 完整周期数 * 7 + 当前周期内的天数位置
	cout << d * 7 + e[f] << "\n";
	
	return 0;
}
