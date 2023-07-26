#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int a, b;
  cin >> a >> b;

  cout << a * (b % 10) << '\n' << a * (b / 10 % 10) << '\n' << a * (b / 100) << '\n' << a * b;

  return 0;
}
