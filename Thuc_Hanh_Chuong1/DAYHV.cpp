#include <iostream>
#include <vector>
using namespace std;

int main() {
   int N;
   cin >> N;

   vector<bool> check(N + 1, false);
   bool DHV = true;

   for (int i = 0; i < N; ++i) {
       int a;
       cin >> a;
       if (a < 1 || a > N) {
           DHV = false;
       }
       else if (check[a]) {
           DHV = false;
       }
       else {
           check[a] = true;
       }
   }

   if (DHV) {
       cout << "YES" << endl;
   }
   else {
       cout << "NO" << endl;
   }

   return 0;
}