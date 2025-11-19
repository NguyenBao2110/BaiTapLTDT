#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

#define FI "EulerDanhSachKe.inp"
#define FO "EulerDanhSachKe.out"

int n;
vector<multiset<int>> DSK; 
vector<int> CE;           


int find_start_vertex() {
    for (int i = 1; i <= n; ++i)
        if (!DSK[i].empty()) return i;
    return 1;
}


bool IsEuler() {
  
    for (int i = 1; i <= n; ++i)
        if (DSK[i].size() % 2 != 0) return false;


    int start = -1;
    for (int i = 1; i <= n; ++i) if (!DSK[i].empty()) { start = i; break; }
    if (start == -1) return true;

    vector<int> visited(n + 1, 0);
    stack<int> st;
    st.push(start);
    visited[start] = 1;

    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (int v : DSK[u]) {
            if (v < 1 || v > n) continue; 
            if (!visited[v]) {
                visited[v] = 1;
                st.push(v);
            }
        }
    }

   
    for (int i = 1; i <= n; ++i)
        if (!DSK[i].empty() && !visited[i])
            return false;

    return true;
}

void Euler(int start) {
    CE.clear();
    if (start < 1 || start > n) return;

    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!DSK[u].empty()) {
            int v = *DSK[u].begin(); // lấy một đỉnh kề
            // xóa một lần cạnh (u,v) và (v,u)
            auto it1 = DSK[u].find(v);
            if (it1 != DSK[u].end()) DSK[u].erase(it1);
            auto it2 = DSK[v].find(u);
            if (it2 != DSK[v].end()) DSK[v].erase(it2);
            st.push(v);
        }
        else {
            st.pop();
            CE.push_back(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(FI, "r", stdin);
    //freopen(FO, "w", stdout);

    if (!(cin >> n)) return 0;
    DSK.assign(n + 1, multiset<int>{});

    // Nhập danh sách kề: mỗi dòng kết thúc bằng -1
    for (int i = 1; i <= n; ++i) {
        int x;
        while (cin >> x && x != -1) {
            // CHÚ Ý: chỉ chèn các láng giềng hợp lệ trong [1..n]
            if (x >= 1 && x <= n) DSK[i].insert(x);
            // nếu x không hợp lệ thì bỏ qua (tránh out-of-range sau này)
        }
    }

    if (!IsEuler()) {
        cout << "Do thi khong co chu trinh Euler\n";
        return 0;
    }

    int start = find_start_vertex();
    Euler(start);

    // In kết quả an toàn
    if (CE.empty()) {
        cout << start << '\n';
    }
    else {
        for (int i = (int)CE.size() - 1; i >= 0; --i) {
            cout << CE[i] << (i == 0 ? '\n' : ' ');
        }
    }
    return 0;
}
