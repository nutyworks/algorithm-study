#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int x, y;
  cin >> x >> y;

  if (x > 0 && y > 0) {
    cout << 1;
  } else if (x < 0 && y > 0) {
    cout << 2;
  } else if (x < 0 && y < 0) {
    cout << 3;
  } else if (x > 0 && y < 0) {
    cout << 4;
  }

  return 0;
}
