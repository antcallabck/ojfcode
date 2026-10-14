#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
using ll = long long ;
#define MAXN 305
#define MAXN 305

ll a[MAXN][MAXN];
int dist[MAXN][MAXN];
int vis[MAXN][MAXN];
int vis_token = 0; 

int n, m, k;

bool check(int x) {
	vis_token++;
	deque<ll> dq;
	int start_cost = (a[0][0] < x ? 1 : 0);
	dist[0][0] = start_cost;
	vis[0][0] = vis_token;
	dq.push_front(0);
	int dr[] = {-1, 1, 0, 0};
	int dc[] = {0, 0, -1, 1};
	while (!dq.empty()) {
		ll rc = dq.front();
		dq.pop_front();
		int r = rc >> 32;
		int c = rc & 0xffffffff;
    	if (r == n - 1 && c == m - 1) {
			if (dist[r][c] <= k) return true;
		}
    	if (dist[r][c] > k) continue;
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
				int w = (a[nr][nc] < x ? 1 : 0);
				if (vis[nr][nc] != vis_token) {
					vis[nr][nc] = vis_token;
					dist[nr][nc] = 1e9;
				}
				
				if (dist[r][c] + w < dist[nr][nc]) {
					dist[nr][nc] = dist[r][c] + w;
					ll nrc = (ll)nr << 32 | nc;
					
					if (w == 0) {
						dq.push_front(nrc); // 边权为 0 往前插
					} else {
						dq.push_back(nrc);  // 边权为 1 往后插
					}
				}
			}
		}
	}
	
	// 跑完后检查终点是否可达且代价合法
	return (vis[n - 1][m - 1] == vis_token && dist[n - 1][m - 1] <= k);
}
int main(){
	cin >> n >> m >>k;
	for(int r = 0 ;r < n ;r++){
		for(int c =0; c < m ;c++){
			cin>> a[r][c];
		}
	}
	ll l =1; 
	ll r = 1e9;
	ll ans = 1;
	while(l <= r){
		int m = l +(r-l)/2;
		if(check(m)){
			ans = m;
			l = m +1;
		}else{
			r =m -1;
		}
	}
	cout << ans;
	
	return 0;
}
