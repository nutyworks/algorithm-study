#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int a, b, c;
  cin >> a >> b >> c;
  a = (a * 60 + b + c) % 1440;
  cout << a / 60 << ' ' << a % 60;

  return 0;
}
