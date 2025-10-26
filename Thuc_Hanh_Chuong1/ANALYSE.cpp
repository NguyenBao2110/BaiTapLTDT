#include <iostream>
#include <vector>
using namespace std;
vector<int> sieve(int n) {
   vector<bool> LSNT(n + 1, true);
   LSNT[0] = LSNT[1] = false;
   for (int p = 2; p * p <= n; ++p) {
       if (LSNT[p]) {
           for (int i = p * p; i <= n; i += p) {
              LSNT[i] = false;
           }
       }
   }
   vector<int> SNT;
   for (int p = 2; p <= n; ++p) {
       if (LSNT[p]) {
          SNT.push_back(p);
       }
   }
   return SNT;
}

long long legendre(int n, int p) {
   long long M = 0;
   while (n > 0) {
       n /= p;
       M += n;
   }
   return M;
}

int main() {
   int N;
   while (cin >> N) {
       if (N < 2) {
           cout << "" << endl;
           continue;
       }
       vector<int> SNT = sieve(N);
       for (size_t i = 0; i < SNT.size(); ++i) {
           long long M = legendre(N, SNT[i]);
          cout << M;
           if (i < SNT.size() - 1) {
               cout << " ";
           }
       }
       cout << endl;
   }
   return 0;
}