#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;
struct Edge {
	int to;       // 目标节点
	ll w;  // 边权
};
using PII = pair<long long, int>;
using Heap = priority_queue<PII, vector<PII>, greater<PII>>;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, S, T;
	if (!(cin >> n >> m >> S >> T)) return 0;
	vector<vector<Edge>> adj(n+1);
	for(int i =0 ;i < m ;i++){
		int u , v;
		ll w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<ll> dist(n+1 ,INF);
	vector<int> parent(n+1, -1);
	Heap pq;
	dist[S] =0;
	pq.push({0 ,S});
	while(!pq.empty()){
		PII node = pq.top();
		ll d = node.first;
		int u = node.second;
		pq.pop();
		if(d > dist[u])continue;
		vector<Edge> & edges = adj[u];
		for(int i=0 ;i < edges.size() ;i++){
			Edge & e = edges[i];
			int v = e.to;
			ll w = e.w;
			//松弛操作
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.push({dist[v] , v});
			}
		}
	}
	if(dist[T] == INF){
		cout << "-1\n";
		return 0;
	}
	cout << dist[T] << "\n";
	vector<int>path;
	for(int  i = T ; i != -1 ; i= parent[i]){
		path.push_back(i);
		if(i == S){
			break;
		}
	}
	reverse(path.begin(), path.end());
	for (size_t i = 0; i < path.size(); ++i) {
		if(i == path.size() - 1){
			cout << path[i];
		}else{
		    cout << path[i] << " ";
		}
	}
	cout << "\n";	
	return 0;
}
