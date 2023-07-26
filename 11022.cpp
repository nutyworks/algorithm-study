#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int tc, a, b;

  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cin >> a >> b;
    cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
  }

  return 0;
}
