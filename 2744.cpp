#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  string s;
  cin >> s;

  for (char c : s) {
    if (c >= 97) cout << (char)(c - 32);
    else cout << (char)(c + 32);
  }

  return 0;
}
