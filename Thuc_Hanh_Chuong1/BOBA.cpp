#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
   int T;
   cin >> T;

   while (T--) {
       string s;
       cin >> s;
       map<string, int> tanso;


       for (size_t i = 0; i + 3 <= s.length(); ++i) {
           string bo_ba = s.substr(i, 3);
           tanso[bo_ba]++;
       }
       int max_tanso = 0;
       if (!tanso.empty()) {
           for (map<string, int>::iterator it = tanso.begin(); it != tanso.end(); it++) {
               if (it->second > max_tanso) {
                   max_tanso = it->second;
               }
           }
       }

       cout << max_tanso << endl;
   }

   return 0;
}