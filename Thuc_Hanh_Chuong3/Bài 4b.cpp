#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

#define FI "LIENTHONGDFS.INP"
#define FO "LIENTHONGDFS.OUT"

int n, x;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;

void DFS(int s) {
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
        cout << u << " ";
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
}

void solve() {
    char line[1000];
    stringstream sline;
    int v;
    cin >> n >> x;
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

    DFS(x);
}

int main() {
    //freopen(FI, "rt", stdin);
    // freopen(FO, "wt", stdout);
    solve();
    return 0;
} 