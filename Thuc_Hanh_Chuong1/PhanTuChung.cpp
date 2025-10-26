#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

void NhapMang(int n, unordered_set<int>& s) {
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        s.insert(val);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nx, ny, nz;

    cin >> nx;
    unordered_set<int> set_x;
    NhapMang(nx, set_x);
    cin >> ny;
    unordered_set<int> set_y;
    NhapMang(ny, set_y);
    cin >> nz;
    unordered_set<int> set_z;
    NhapMang(nz, set_z);
    unordered_map<int, int> counts;
    for (int num : set_x) {
        counts[num]++;
    }
    for (int num : set_y) {
        counts[num]++;
    }
    for (int num : set_z) {
        counts[num]++;
    }

    vector<int> PTC;
    for (const auto& pair : counts) {
        if (pair.second == 3) {
            PTC.push_back(pair.first);
        }
    }
    sort(PTC.begin(), PTC.end());
    cout << PTC.size() << endl;
    for (size_t i = 0; i < PTC.size(); ++i) {
        cout << PTC[i];
        if (i < PTC.size() - 1) {
           cout << " ";
        }
    }
    cout << endl;

    return 0;
}