#include <iostream>

using namespace std;

int main() {
	// 提升标准 I/O 操作的执行效率
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long n, k;
	if (cin >> n >> k) {
		long long m = n - k; // 余下的不通过圆心的刀数
		long long total = 0;
		
		if (k == 0) {
			// 没有一刀通过圆心：经典的平面直线分割区域公式
			total = 1 + n * (n + 1) / 2;
		} else {
			// 有 k 刀通过圆心，m 刀不通过圆心
			total = 2 * k + k * m + m * (m + 1) / 2;
		}
		
		cout << total << "\n";
	}
	
	return 0;
}
