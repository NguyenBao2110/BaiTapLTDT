#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;
vector<pair<int, int>> tree;

int BFS(int s) {
    int cnt = 0;
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    open.clear();
    tree.clear();

    open.push_back(s);
    visited[s] = true;

    while (!open.empty()) {
        cnt++;
        int u = open.front();
        open.pop_front();
        for (int v : adjlist[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                tree.push_back({ u, v });
                open.push_back(v);
            }
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    adjlist.resize(n + 1);
    visited.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(adjlist[i].begin(), adjlist[i].end());

    BFS(1);

    cout << tree.size() << "\n";
    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i].first << " " << tree[i].second << "\n";
    }
}

int main() {
    solve();
    return 0;
}