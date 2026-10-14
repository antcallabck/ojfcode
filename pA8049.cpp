#include <iostream>
using namespace std;
using ll = long long;
struct eage{
	int u , v ;
	ll w;
};
#define MAXN 100005
#define MAXM 200005
const ll INF = 0x3f3f3f3f3f3f3f3fLL; // 定义无穷大
struct eage eages[MAXM];
ll v[MAXN];
ll dist[MAXN];
int main(){
	int n,m,a,b;
	cin >>n>>m>>a>>b;
	for(int i=0 ;i < n; i++){
		cin >> v[i];
	}
	for(int i=0 ;i < m ;i++){
		int x , y;
		cin >> x >> y;
		eages[i] = {x, y , v[y] - v[x] +1};
	}
	for(int i =0 ;i < n ;i ++){
		dist[i] = INF;
	}
	dist[a] = 0;
	for(int i =0 ;i < n -1; i++){
		bool updated = 0;
		for(int j =0 ; j < m ;j ++){
			int u = eages[j].u;
			int v = eages[j].v;
			ll w = eages[j].w;
			if(dist[u] != INF && dist[u] +w < dist[v]){
				dist[v] = dist[u] +w;
				updated = 1;
			}
		}
		if(updated ==0){
			break;
		}
	}
	// 输出结果
	if (dist[b] == INF) {
		cout << "No solution\n";
	} else {
		cout << dist[b] << "\n";
	}
	return 0;
}
