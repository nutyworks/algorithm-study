// Written by lemonajoc @ 7/22/2023, 1:38:20 PM
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int> shark;

inline int pos(int raw, int width) {
  int rx = (raw + 1000 * (width - 1) * 2) % ((width - 1) * 2);
  return rx >= width ? (width - 1) * 2 - rx : rx;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  vector<shark> sharks;
  int r, c, m;

  cin >> r >> c >> m;

  int dx = 5, x = 0;

  for (int i = 0; i < 100; i++) {
    x += dx;
    int rx = (x + 1000 * (9 - 1) * 2) % ((9 - 1) * 2);
    cout << (rx >= 9 ? (9 - 1) * 2 - rx : rx) << ' ';
  }

  // while (m--) {
  //   int sr, sc, s, d, z;
  //   cin >> sr >> sc >> s >> d >> z;
  //
  //   int dx = d == 3 ? 1 : d == 4 ? -1 : 0;
  //   int dy = d == 1 ? -1 : d == 2 ? 1 : 0;
  //   sharks.emplace_back(sr, sc, dx * s, dy * s, z);
  // }

  // for (int i = 0; i < c; i++) {
  //   for (auto &[sr, sc, dx, dy, size] : sharks) {
  //   }
  // }

  return 0;
}
