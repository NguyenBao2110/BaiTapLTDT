#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

#define FI "LIENTHONGDFS.INP"
#define FO "LIENTHONGDFS.OUT"

int n, x, y;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;

int DFS(int s) {
    int cnt = 0;


    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);

    open.clear();
    open.push_back(s);
    //visited[s] = true;
    while (!open.empty()) {

        int u = open.back();
        open.pop_back();
        visited[u] = true;
        cnt = cnt + 1;
        for (set<int>::iterator it = adjlist[u].begin();
            it != adjlist[u].end(); it++) {
            int v = *it;
            if (visited[v] == false) {
                //visited[v] = true;
                parent[v] = u;
                open.push_back(v);
            }
        }
    }
    return cnt;
}

void solve() {
    char line[1000];
    stringstream sline;
    int v;
    cin >> n >> x>>y;
    cin.ignore(1000, '\n');

    adjlist.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin.getline(line, 1000);

        stringstream sline(line);
        while (sline >> v) {
            adjlist[i].insert(v);
        }

    }

    visited.resize(n + 1);
    open.resize(n + 1);
    parent.resize(n + 1);

    int cnt = DFS(x);
     //truy vết đường đi từ y về x
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
    cout << endl;
}

int main() {
    //freopen(FI, "rt", stdin);
    // freopen(FO, "wt", stdout);
    solve();
    return 0;
}
