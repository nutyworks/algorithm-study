// Written by lemonajoc @ 7/24/2023, 11:52:51 AM
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    int m, n, x, y, maxyear;
    bool success = false;
    cin >> m >> n >> x >> y;
    maxyear = lcm(m, n);

    for (int year = 0; year < maxyear; year++) {
      if (x == year % m + 1 && y == year % n + 1) {
        cout << year + 1 << '\n';
        success = true;
        break;
      }
    }

    if (!success) cout << -1 << '\n';
  }

  return 0;
}

/*
 * max year = lcm(m, n)
 * ith year = (year % m) + 1, (year % n) + 1
 * 
 * 39999 40000
 */
