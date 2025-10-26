#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Vertex {
    int v;
    int w;
};

vector<vector<Vertex>> adjList;
vector<int> dist;
vector<bool> label;
vector<int> path;
vector<int> pre;
queue<int> q;
const int INF = 1000000000;

void Dijkstra(int s) {
    int n = static_cast<int>(adjList.size()) - 1;
    dist.resize(n + 1, INF);
    dist[s] = 0;
    pre.resize(n+1, -1);
    label.resize(n+1, false);
    q.push(s);
    label[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        label[u] = false;

        for (auto e : adjList[u]) {
            int v = e.v;
            int w = e.w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                if (!label[v]) {
                    q.push(v);
                    label[v] = true;
                }
            }
        }
    }
}

void TimDuong(int s, int t) {
        path.clear();
    
        if (dist[t] == INF) return;  // không có đường đi
    
        for (int u = t; u != s; u = pre[u]) {
            if (u == -1) return; // tránh vòng lặp vô hạn nếu không có đường đi
            path.push_back(u);
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
}

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    adjList.assign(n + 1, {}); // đánh số từ 1 -> n

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({ v, w });
    }

    Dijkstra(s);
    TimDuong(s, t);

    if (dist[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << "\n";
        return;
    }

    cout << path.size() << " " << dist[t] << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
