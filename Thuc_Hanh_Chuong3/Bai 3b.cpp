#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
#include <queue>
using namespace std;


int n;
vector< vector<int> > adj;
vector<int> color; // -1: chưa tô, 0/1: hai màu

bool isBipartite() {
    color.assign(n + 1, -1);
    for (int start = 1; start <= n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u] ^ 1; // tô màu đối
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return false; // phát hiện cạnh cùng màu
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n;
    adj.assign(n + 1, {});
    // đọc danh sách kề
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v; cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    if (isBipartite())
        cout << "Do thi phan doi\n";
    else
        cout << "Do thi khong phan doi\n";

    return 0;
}