#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

const int INF = 1e9;
vector<map<int, int>> adj;
vector<bool> visited;
vector<int> nearNode, pre;
vector<pair<int, int>> tree;
int n, m;

void Prim() {
    visited.assign(n + 1, false);
    nearNode.assign(n + 1, INF);
    pre.assign(n + 1, -1);
    tree.clear();

    int s = 1; // bắt đầu từ đỉnh 1
    nearNode[s] = 0;

    for (int i = 1; i <= n; i++) {
        int uMin = -1;

        // Tìm đỉnh chưa thăm có trọng số nhỏ nhất
        for (int u = 1; u <= n; u++) {
            if (!visited[u] && (uMin == -1 || nearNode[u] < nearNode[uMin])) {
                uMin = u;
            }
        }

        if (uMin == -1) break; // không còn đỉnh nào

        visited[uMin] = true;

        // Nếu không phải là đỉnh bắt đầu thì thêm cạnh vào cây khung
        if (pre[uMin] != -1)
            tree.push_back({pre[uMin], uMin});

        // Cập nhật khoảng cách đến các đỉnh kề
        for (auto &[v, w] : adj[uMin]) {
            if (!visited[v] && w < nearNode[v]) {
                nearNode[v] = w;
                pre[v] = uMin;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    Prim();

    int total = 0;
    cout << "Cac canh thuoc cay khung nho nhat:\n";
    for (auto [u, v] : tree) {
        cout << u << " - " << v << " : " << adj[u][v] << "\n";
        total += adj[u][v];
    }
    cout << "Tong trong so cay khung = " << total << "\n";
    return 0;
}
