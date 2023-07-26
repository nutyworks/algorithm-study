#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  string s1, s2;
  cin >> s1 >> s2;
  cout << (s1.size() >= s2.size() ? "go" : "no");

  return 0;
}
