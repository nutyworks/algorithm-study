// Written by lemonajoc @ 7/23/2023, 10:25:57 AM
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

queue<tuple<char, int, int>> q = {};
set<char> keys = {};
char board[100][100];

int steal_doc() {
  int cnt = 0, w, h;

  cin >> h >> w;

  while (!q.empty()) q.pop();
  keys.clear();

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> board[i][j];

      if (i > 0 && i < h - 1 && j > 0 && j < w - 1) continue;

      if (board[i][j] == '.') {
        q.emplace(0, j, i);
      } else if ('a' <= board[i][j] && board[i][j] <= 'z') {
        keys.insert(board[i][j] - 32);
        q.emplace(0, j, i);
        board[i][j] = '*';
      } else if ('A' <= board[i][j] && board[i][j] <= 'Z') {
        q.emplace(board[i][j], j, i);
        board[i][j] = '*';
      } else if (board[i][j] == '$') {
        cnt++;
        q.emplace(0, j, i);
        board[i][j] = '*';
      }
    }
  }

  string skeys;
  cin >> skeys;

  if (skeys[0] != '0') {
    for (char key : skeys) keys.insert(key - 32);
  }

  bool changed = true;

  while (!q.empty() && changed) {
    changed = false;
    int nq = q.size();
    while (nq--) {
      auto [door, tx, ty] = q.front();

      if (door && !keys.count(door)) {
        q.emplace(door, tx, ty);
        q.pop();
        continue;
      }

      changed = true;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = tx + dx[i], ny = ty + dy[i];

        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if (board[ny][nx] == '*') continue;

        if (board[ny][nx] == '.') {
          q.emplace(0, nx, ny);
        } else if ('a' <= board[ny][nx] && board[ny][nx] <= 'z') {
          keys.insert(board[ny][nx] - 32);
          q.emplace(0, nx, ny);
        } else if ('A' <= board[ny][nx] && board[ny][nx] <= 'Z') {
          q.emplace(board[ny][nx], nx, ny);
        } else if (board[ny][nx] == '$') {
          cnt++;
          q.emplace(0, nx, ny);
        }
        board[ny][nx] = '*';
      }
    }
  }

  return cnt;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    int result = steal_doc();
    cout << result << '\n';
  }

  return 0;
}
