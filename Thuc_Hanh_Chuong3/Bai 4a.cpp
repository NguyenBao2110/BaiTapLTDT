#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
#include <queue>
using namespace std;

int n;
vector< set<int> > adj;

int BFS_components(vector< set<int> >& g, vector<bool> bannedVertex) {
    vector<bool> visited(n + 1, false);
    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && !bannedVertex[i]) {
            comps++;
            queue<int> q; q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : g[u]) {
                    if (!visited[v] && !bannedVertex[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return comps;
}
void solve() {
    int x, y, z;
    cin >> n >> x >> y >> z;
    adj.assign(n + 1, {});

    
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v; cin >> v;
            if (v == -1) break;
            adj[i].insert(v);
        }
    }

   
    vector<bool> none(n + 1, false);
    int comp0 = BFS_components(adj, none);

   
    bool isBridge = false;
    {
       
        vector< set<int> > g = adj;
        g[x].erase(y);
        g[y].erase(x);
        int comp1 = BFS_components(g, none);
        if (comp1 > comp0) isBridge = true;
    }

    
    bool isArticulation = false;
    {
        vector<bool> banned(n + 1, false);
        banned[z] = true;
        int comp1 = BFS_components(adj, banned);
        if (comp1 > comp0) isArticulation = true;
    }

    cout << (isBridge ? "canh cau" : "khong la canh cau") << "\n";
    cout << (isArticulation ? "dinh khop" : "khong la dinh khop") << "\n";
}


int main() {
    solve();
    return 0;
}