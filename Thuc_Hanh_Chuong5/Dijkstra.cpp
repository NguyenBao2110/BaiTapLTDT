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
//    dist.resize(n + 1, INF);
//    dist[s] = 0;
//    pre.resize(n+1, -1);
//    label.resize(n+1, false);
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
//        if (u == -1) break;  // không còn đỉnh có thể cập nhật
//        label[u] = true;
//
//        // --- Cập nhật các đỉnh kề v của u ---
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
//// ======== HÀM TRUY VẾT ĐƯỜNG ĐI ========
//void TimDuong(int s, int t) {
//    path.clear();
//
//    if (dist[t] == INF) return;  // không có đường đi
//
//    for (int u = t; u != s; u = pre[u]) {
//        if (u == -1) return; // tránh vòng lặp vô hạn nếu không có đường đi
//        path.push_back(u);
//    }
//    path.push_back(s);
//    reverse(path.begin(), path.end());
//}
//
//// ======== HÀM CHÍNH ========
//void solve() {
//    int n, m, s, t;
//    cin >> n >> m >> s >> t;
//
//    adjList.assign(n + 1, {}); // đánh số từ 1 -> n
//
//    for (int i = 0; i < m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        adjList[u].push_back({ v, w });
//    }
//
//    Dijkstra(s);
//    TimDuong(s, t);
//
//    if (dist[t] == INF) {
//        cout << "Khong co duong di tu " << s << " den " << t << "\n";
//        return;
//    }
//
//    cout << path.size() << " " << dist[t] << "\n";
//    for (int v : path) cout << v << " ";
//    cout << "\n";
//}
//
//int main() {
//    solve();
//    return 0;
//}

