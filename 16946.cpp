// Written by lemonajoc @ 7/23/2023, 8:38:48 AM
#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int conn[1002][1002];
int area[1002][1002];
bool visited[1002][1002];
int a = 0;

void bfs(int board[1002][1002], int r, int c, int n, int m) {
  int cnt = 0;
  a++;

  queue<pair<int, int>> v;
  queue<pair<int, int>> q;

  q.emplace(r, c);
  visited[r][c] = true;

  while (!q.empty()) {
    auto [tr, tc] = q.front();
    v.emplace(tr, tc);
    q.pop();
    cnt++;

    for (int i = 0; i < 4; i++) {
      int nr = tr + dr[i], nc = tc + dc[i];

      if (board[nr][nc]) continue;
      if (visited[nr][nc]) continue;

      q.emplace(nr, nc);
      visited[nr][nc] = true;
    }
  }

  int nq = v.size();
  while (nq--) {
    auto [tr, tc] = v.front();
    v.pop();

    conn[tr][tc] = cnt;
    area[tr][tc] = a;
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, board[1002][1002];

  cin >> n >> m;

  fill(board[0], board[0] + m + 2, 1);
  fill(board[n + 1], board[n + 1] + m + 2, 1);

  for (int i = 1; i <= n; i++) {
    board[i][0] = board[i][m + 1] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      board[i][j] = c - '0';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!board[i][j] && !visited[i][j]) {
        bfs(board, i, j, n, m);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j] == 1) {
        int sum = 0;
        set<int> sumarea = {};

        for (int d = 0; d < 4; d++) {
          int nr = i + dr[d], nc = j + dc[d];

          if (board[nr][nc]) continue;
          if (sumarea.count(area[nr][nc]) > 0) continue;

          sum += conn[nr][nc];
          sumarea.insert(area[nr][nc]);
        }

        cout << (sum + 1) % 10;
      } else {
        cout << '0';
      }
    }
    cout << '\n';
  }

  return 0;
}
