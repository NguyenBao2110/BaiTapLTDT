#include <iostream>
#include <map>
using namespace std;

long long DSK(long long n) {
   if (n < 0) return 0;
   long long count = 0;
   while (n >= 5) {
       n /= 5;
       count += n;
   }
   return count;
}

int main() {
   map<int, long long> BL;
   for (int i = 1; i <= 1000; ++i) {
       BL[i] = DSK(i);
   }

   int N;
   while (cin >> N) {    
       if (N <= 1000) {
           cout << BL[N] << endl;
       }
       else {
           cout << DSK(N) << endl;
       }
   }

   return 0;
}
