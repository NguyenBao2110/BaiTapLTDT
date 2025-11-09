#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

void Make_Tree() {
    vector<tuple<int, int, int>> edges;
    // Tạo danh sách cạnh
    for (int u = 1; u <= n; u++) {
        for (auto p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (u < v)
                edges.push_back({ w, u, v });
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> connected(n + 1);
    for (int i = 1; i <= n; i++)
        connected[i] = i;

    vector<pair<int, int>> tree(n + 1, { -1, 0 });
    long long total = 0;
    int edge_count = 0; // ✅ đếm số cạnh trong cây khung

    for (auto edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        if (connected[u] != connected[v]) {
            int umin = u, vmin = v;
            if (u > v) swap(umin, vmin);

            tree[vmin] = { umin, w };
            total += w;
            edge_count++; // ✅ chọn được 1 cạnh mới

            int oldSet = connected[v];
            int newSet = connected[u];
            for (int i = 1; i <= n; i++) {
                if (connected[i] == oldSet)
                    connected[i] = newSet;
            }
        }
    }

    // ✅ Dòng đầu tiên: số cạnh và tổng trọng số
    cout << edge_count << " " << total << "\n";

    // ✅ Sau đó in danh sách các cạnh trong cây khung nhỏ nhất
    for (int i = 1; i <= n; i++) {
        if (tree[i].first != -1)
            cout << tree[i].first << " " << i << " " << tree[i].second << "\n";
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    Make_Tree();
    return 0;
}

