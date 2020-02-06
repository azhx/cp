#include <bits/stdc++.h>
using namespace std;
#define toDigit(x) (x-'0')

int primes [26] = {2, 3, 5, 7, 11, 13, 17, 19,
                23, 29, 31, 37, 41, 43, 47, 53, 59,
                61, 67, 71, 73, 79, 83, 89, 97, 101};

int main () {
  int N = 5;
  vector <int> results;
  for (int i = 0; i < N; i++) {
    int num, above = 0, below = 0, diff = 1, primea, primeb;
    cin >> num;
    while (above < 2 || below < 2){
      int newa = num + diff, newb = num - diff;
      for (int j = 0; j < 26; j++){
        if (primes[j] == newa){
          above += 1;
          if (above == 2){
            primea = newa;
          }
        }
      }
      for (int j = 0; j < 26; j++){
        if (primes[j] == newb){
          below += 1;
          if (below == 2){
            primeb = newb;
          }
        }
      }
      diff += 1;
    }
    if ((primea - num) > (num- primeb)){
      results.push_back(primeb);
    } else {
      results.push_back(primea);
    }
  }
  for (unsigned int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }
  return 0;
}
