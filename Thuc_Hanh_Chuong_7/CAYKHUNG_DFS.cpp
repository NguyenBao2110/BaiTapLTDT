#include <iostream>
#include <vector>
#include <stack> 
#include <algorithm>
#include <utility>

using namespace std;


int n, m;
vector<vector<int>> adjlist;
vector<bool> visited;
stack<int> open;
vector<int> parent;
vector<pair<int, int>> tree;


void DFS(int s) {
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    while (!open.empty()) open.pop();
    tree.clear();
    open.push(s);
    visited[s] = true;

    
    while (!open.empty()) {
       
        int u = open.top();
        open.pop();

        for (auto it = adjlist[u].rbegin(); it != adjlist[u].rend(); ++it) {
            int v = *it;
            if (!visited[v]) {
                
                parent[v] = u;
                tree.push_back({ u, v });
                visited[v] = true;
                open.push(v);
            }
        }
    }
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

 
    DFS(1);

    cout << tree.size() << "\n";
    for (int i = 0; i < tree.size(); i++) {
        cout << min(tree[i].first, tree[i].second) << " " << max(tree[i].first, tree[i].second) << "\n";
    }
}

int main() {
    
    solve();
    return 0;
}