// Written by lemonajoc @ 7/24/2023, 11:44:33 AM
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char campus[600][600];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  queue<pair<int, int>> q;
  int n, m, cnt = 0;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> campus[i][j];
      if (campus[i][j] == 'I') {
        q.emplace(j, i);
        campus[i][j] = 'X';
      }
    }
  }

  while (!q.empty()) {
    auto [tx, ty] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = tx + dx[i], ny = ty + dy[i];

      if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
      if (campus[ny][nx] == 'X') continue;

      if (campus[ny][nx] == 'P') cnt++;
      q.emplace(nx, ny);
      campus[ny][nx] = 'X';
    }
  }

  if (cnt) cout << cnt;
  else cout << "TT";

  return 0;
}
