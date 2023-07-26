#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    string s;
    cin >> s;
    cout << s[0] << s[s.size() - 1] << '\n';
  }

  return 0;
}
