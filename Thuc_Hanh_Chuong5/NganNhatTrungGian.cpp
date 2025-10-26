//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct Vertex {
//    int v;
//    int w;
//};
//
//vector<vector<Vertex>> adjList;
//vector<int> dist;
//vector<bool> label;
//vector<int> path;
//vector<int> pre;
//const int INF = 1000000000;
//
//void Dijkstra(int s) {
//    int n = static_cast<int>(adjList.size()) - 1;
//    dist.assign(n + 1, INF);
//    dist[s] = 0;
//    pre.assign(n + 1, -1);
//    label.assign(n + 1, false);
//    for (int k = 1; k <= n; k++) {
//
//        int u = -1;
//        int minDist = INF;
//        for (int i = 1; i <= n; i++) {
//            if (!label[i] && dist[i] < minDist) {
//                minDist = dist[i];
//                u = i;
//            }
//        }
//
//        if (u == -1) break;  
//        label[u] = true;
//
//        for (auto edge : adjList[u]) {
//            int v = edge.v;
//            int w = edge.w;
//
//            if (!label[v] && dist[v] > dist[u] + w) {
//                dist[v] = dist[u] + w;
//                pre[v] = u;  // truy vết
//            }
//        }
//    }
//}
//
//void TimDuong(int s, int t) {
//    path.clear();
//
//    if (dist[t] == INF) return;  
//
//    for (int u = t; u != s; u = pre[u]) {
//        if (u == -1) return; 
//        path.push_back(u);
//    }
//    path.push_back(s);
//    reverse(path.begin(), path.end());
//}
//
//
//void solve() {
//    int n, m, s, t, x;
//    cin >> n >> m >> s >> t>>x;
//
//    adjList.assign(n + 1, {});
//
//    for (int i = 0; i < m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        adjList[u].push_back({ v, w });
//    }
//
//    Dijkstra(s);
//    TimDuong(s, x);
//
//    if (dist[x] == INF) {
//        cout << "Khong co duong di tu " << s << " den " << x << "\n";
//        return;
//    }
//
//    vector<int>path1 = path;
//    int k = dist[x];
//
//    Dijkstra(x);
//    TimDuong(x, t);
//
//    if (dist[t] == INF) {
//        cout << "Khong co duong di tu " << x << " den " << t << "\n";
//        return;
//    }
//	k += dist[t];
//    for (int i = 1; i < (int)path.size(); i++) {
//        path1.push_back(path[i]);
//    }
//    cout << path1.size() << " " << k<< "\n";
//    for (int v : path1) cout << v << " ";
//    cout << "\n";
//}
//
//int main() {
//    solve();
//    return 0;
//}