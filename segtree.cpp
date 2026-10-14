
#include <iostream>
using namespace std;

const int N = 100005;

int n, m;
long long a[N];

struct Node {
	long long sum;   // 当前区间的和
	long long lazy;  // 懒标记
};

Node tree[N * 4];

// 1. 向上合并
void pushup(int p) {
	tree[p].sum = tree[p * 2].sum
	+ tree[p * 2 + 1].sum;
}

// 2. 修改整个节点管理的区间
void apply(int p, int l, int r, long long v) {
	tree[p].sum += (r - l + 1) * v;
	tree[p].lazy += v;
}

// 3. 向下传递懒标记
void pushdown(int p, int l, int r) {
	if (tree[p].lazy == 0) return;
	
	int mid = (l + r) / 2;
	long long v = tree[p].lazy;
	
	apply(p * 2, l, mid, v);
	apply(p * 2 + 1, mid + 1, r, v);
	
	tree[p].lazy = 0;
}

// 4. 建树
void build(int p, int l, int r) {
	tree[p].lazy = 0;
	
	if (l == r) {
		tree[p].sum = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	
	pushup(p);
}

// 5. 区间修改：[L,R] 全部加 v
void update(int p, int l, int r,
			int L, int R, long long v) {
	
	if (L <= l && r <= R) {
		apply(p, l, r, v);
		return;
	}
	
	pushdown(p, l, r);
	
	int mid = (l + r) / 2;
	
	if (L <= mid) {
		update(p * 2, l, mid, L, R, v);
	}
	
	if (R > mid) {
		update(p * 2 + 1, mid + 1, r, L, R, v);
	}
	
	pushup(p);
}

// 6. 区间查询：[L,R] 的和
long long query(int p, int l, int r,
				int L, int R) {
	
	if (L <= l && r <= R) {
		return tree[p].sum;
	}
	
	pushdown(p, l, r);
	
	int mid = (l + r) / 2;
	long long ans = 0;
	
	if (L <= mid) {
		ans += query(p * 2, l, mid, L, R);
	}
	
	if (R > mid) {
		ans += query(p * 2 + 1, mid + 1, r, L, R);
	}
	
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	build(1, 1, n);
	
	while (m--) {
		int op, L, R;
		cin >> op >> L >> R;
		
		if (op == 1) {
			long long v;
			cin >> v;
			
			update(1, 1, n, L, R, v);
		}
		else if (op == 2) {
			cout << query(1, 1, n, L, R) << '\n';
		}
	}
	
	return 0;
}

