//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> dist;
////vector<int>path;
//const int INF = 1000000000;
//void Floyd(int n) {
//
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= n; j++) {
//				if (dist[i][k] < INF && dist[k][j] < INF) {
//					if (dist[i][j] > (dist[i][k] + dist[k][j]))
//						dist[i][j] = dist[i][k] + dist[k][j];
//				}
//			}
//		}
//	}
//}
//
//void solve() {
//	int n, m;
//	cin >> n >> m;
//	dist.assign(n + 1, vector<int>(n + 1, INF));
//	/*path.resize(n + 1);*/
//	for (int i = 1; i <= n; i++) {
//		dist[i][i] = 0;
//	}
//	for (int j = 0; j < m; j++)
//	{
//		int u, v, w;
//		cin >> u >> v >> w;
//		dist[u][v] = w;
//		dist[v][u] = w;
//	}
//	Floyd(n);
//
//	for (int i = 1; i <= n; i++) { 
//		for (int j = 1; j <= n; j++) { 
//			if (dist[i][j] == INF) 
//				cout << "INF "; else cout << dist[i][j] << " ";
//		}
//		cout << "\n";
//	}
//}
//int main() {
//	solve();
//	return 0;
//}
