#include <bits/stdc++.h>

using namespace std;

int t[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  string s;
  int total = 0;
  cin >> s;

  for (char c : s) {
    total += t[c - 'A'];
  }

  cout << total;

  return 0;
}
