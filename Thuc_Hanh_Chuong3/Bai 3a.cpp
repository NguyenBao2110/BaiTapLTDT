#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int n;
vector< set<int> > adjlist;   
vector<bool> visited;       


vector<int> BFS(int s) {
    vector<int> component;
    deque<int> q;
    visited[s] = true;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        component.push_back(u);

        for (int v : adjlist[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push_back(v);
            }
        }
    }
    return component;
}

void solve() {
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    adjlist.assign(n + 1, {});       // 1-based
    visited.assign(n + 1, false);

    // Đọc danh sách kề cho từng đỉnh
    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;
        while (ss >> v) {
            if (v == -1) break;      
            adjlist[i].insert(v);
            adjlist[v].insert(i);     
        }
    }

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> comp = BFS(i);
            components.push_back(comp);
        }
    }

    // Xuất kết quả
    cout << components.size() << "\n";
    for (auto& comp : components) {
        for (size_t j = 0; j < comp.size(); j++) {
            if (j) cout << ' ';
            cout << comp[j];
        }
        cout << "\n";
    }
}

int main() {

    solve();
    return 0;
}