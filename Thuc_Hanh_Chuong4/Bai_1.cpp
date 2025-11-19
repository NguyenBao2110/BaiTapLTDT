#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define FI "DOTHIEULER.INP"
#define FO "DOTHIEULER.OUT"

int n;
vector<vector<int>>mtke;

bool IsEuler() {
	deque<int> open;
	vector<int>check(n + 1);
	fill(check.begin(), check.end(), 0);
	open.push_back(1);
	check[1] = 1;
	while (!open.empty()) {
		int u = open.front();
		open.pop_front();
		for (int v = 1; v <= n; v++) {
			if (check[v] == 0 && mtke[u][v] == 1)
			{
				check[v] = 1;
				open.push_back(v);
			}
		}
	}

	bool laLienThong = true;
	for (int u = 1; u <= n && laLienThong == true; u++) {
	    if (check[u] == 0)
	    {
		     laLienThong = false;
	    }
    }
	int cntLe = 0;
	vector<int>deg(n + 1);
	fill(deg.begin(), deg.end(), 0);
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			if (mtke[u][v] == 1)
			{
				deg[u]++;
			}
		}
		cntLe += deg[u] % 2;
	}
	return laLienThong == true && cntLe == 0;
}
 
void FindEuler(vector<int>& cycle) {
	cycle.clear();
	deque<int>stack;
	stack.push_back(1);
	while (!stack.empty()) {
		int u = stack.back();
		bool flag = false;
		for (int v = 1; v <= n; v++) {
			if (mtke[u][v] > 0) {
				stack.push_back(v);
				mtke[u][v]--;
				mtke[v][u]--;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cycle.push_back(u);
			stack.pop_back();
		}
	}
}

void solve() {
	// Nhap ma tran ke
	cin >> n;
	// cout << n;
	mtke.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		mtke[i].resize(n + 1);
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			mtke[i][j] = w;
		}
	}

	bool ans = IsEuler();
	cout << ans << endl;
	vector<int> cycle;
	FindEuler(cycle);
	for (int i = cycle.size() - 1; i >= 0; i--) {
		cout << cycle[i] << " ";
	}
}

int main() {
	//freopen(FI, "rt", stdin);
	// freopen(FO, "wt", stdout);
	solve();
	return 0;
}


;  