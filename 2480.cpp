#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int a, b, c, n, x, m;
  cin >> a >> b >> c;
  n = min({a, b, c});
  x = max({a, b, c});
  m = a + b + c - n - x;

  if (n == m && m == x) cout << 10000 + m * 1000;
  else if (n == m) cout << 1000 + m * 100;
  else if (m == x) cout << 1000 + m * 100;
  else cout << x * 100;

  return 0;
}
