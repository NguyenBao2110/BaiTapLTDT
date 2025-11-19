#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int n, x, y;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;

int BFS(int s) {
    int cnt = 0;

    // khởi tạo
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    open.clear();

    // bắt đầu BFS từ đỉnh s
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
                open.push_back(v);
            }
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> x >> y;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    adjlist.assign(n + 1, {});
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v == -1) break;      // bỏ qua phần kết thúc -1
            adjlist[i].insert(v);
        }
    }

    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    BFS(x);

    // truy vết đường đi từ y về x
    vector<int> path;
    if (!visited[y]) {               // không có đường đi
        cout << 0 << "\n";
        return;
    }
    for (int v = y; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());

    // in kết quả
    cout << path.size() << "\n";
    for (size_t i = 0; i < path.size(); i++) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << "\n";
}

int main() {
    solve();
    return 0;
}
