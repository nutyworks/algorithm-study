// Written by lemonajoc @ 7/19/2023, 10:32:22 PM
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

short board[1000][1000];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, k, moves = 0;
  queue<tuple<int, int, int>> q;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      board[i][j] = c - '0';
    }
  }

  q.emplace(0, 0, 0);
  board[0][0] = 0xfffe;

  while (!q.empty()) {
    moves++;
    int nq = q.size();
    while (nq--) {
      int tx, ty, tk;
      tie(tx, ty, tk) = q.front();
      q.pop();

      if (tx == m - 1 && ty == n - 1) {
        cout << moves;
        return 0;
      }
      
      for (int i = 0; i < 4; i++) {
        int nx = tx + dx[i], ny = ty + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

        if ((board[ny][nx] & 1) && tk < k && !(board[ny][nx] & (4 << tk))) {
          q.emplace(nx, ny, tk + 1);
          board[ny][nx] |= 0xfffe << (tk + 1);
        }

        if (!(board[ny][nx] & 1) && !(board[ny][nx] & (2 << tk))) {
          q.emplace(nx, ny, tk);
          board[ny][nx] |= 0xfffe << tk;
        }
      }
    }
  }

  cout << -1;

  return 0;
}
