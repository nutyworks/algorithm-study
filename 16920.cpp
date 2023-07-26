// Written by lemonajoc @ 7/20/2023, 9:43:20 AM
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char board[1000][1000];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, p, s[9], cnt[9] = {}, remaining;
  bool finished[9] = {};
  queue<pair<int, int>> q[9];

  cin >> n >> m >> p;
  remaining = p;
  
  for (int i = 0; i < p; i++) cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;

      if (c == '.') {
        board[i][j] = 0;
      } else if (c == '#') {
        board[i][j] = -1;
      } else {
        board[i][j] = c - '0';
        q[c - '1'].emplace(j, i);
      }
    }
  }

  while (remaining) {
    for (int i = 0; i < p; i++) {
      if (finished[i]) continue;
      for (int t = 0; t < s[i]; t++) {
        int nq = q[i].size();
        if (!nq) {
          finished[i] = true;
          remaining--;
          break;
        }
        while (nq--) {
          int tx, ty;
          tie(tx, ty) = q[i].front();
          q[i].pop();
          cnt[i]++;

          for (int d = 0; d < 4; d++) {
            int nx = tx + dx[d], ny = ty + dy[d];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (board[ny][nx] != 0) continue;

            q[i].emplace(nx, ny);
            board[ny][nx] = i + 1;
          }
        }
      }
    }
  }

  for (int i = 0; i < p; i++) cout << cnt[i] << ' ';

  return 0;
}
