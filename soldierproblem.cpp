#include <bits/stdc++.h>
using namespace std;
#define toDigit(x) (x-'0')

int main () {
  int N, ans = 0, bestans = 0, numl = 0, lastl = 0, subl = 0;
  string S;
  cin >> N;
  cin >> S;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'L') {
      numl += 1;
      subl += 1;
      lastl = i;
      ans = lastl - numl + 1 + subl - 1;
      if (ans <= bestans){
        ans = bestans + 1;
      }
      bestans = max(ans, bestans);
    } else if (S[i] == 'R'){
      subl = 0;
    }
  }
  cout << bestans << endl;
  return 0;
}
//LLLLRRLLRLRLLRRRRRLRLLRRRLLLLRRRLLLRLRLLLLRLRRLRLRLRRLRRRLLL
