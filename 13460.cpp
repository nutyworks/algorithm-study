// Written by lemonajoc @ 7/18/2023, 12:52:29 PM
#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char board[10][10];
bool visited[10][10][10][10];

tuple<int, int, int, int> hit_wall(int rx, int ry, int bx, int by, int d) {
  while (true) {
    bool rescaped = board[ry][rx] == 'O';
    bool bescaped = board[by][bx] == 'O';

    bool rmove = 
      !(board[ry + dy[d]][rx + dx[d]] == '#'
        || (!bescaped && ry + dy[d] == by && rx + dx[d] == bx && board[ry + dy[d] * 2][rx + dx[d] * 2] == '#')
        || rescaped);

    bool bmove = 
      !(board[by + dy[d]][bx + dx[d]] == '#'
        || (!rescaped && by + dy[d] == ry && bx + dx[d] == rx && board[by + dy[d] * 2][bx + dx[d] * 2] == '#')
        || bescaped);

    if (rmove) {
      ry += dy[d];
      rx += dx[d];
    }
    if (bmove) {
      by += dy[d];
      bx += dx[d];
    }

    if (!rmove && !bmove) break;
  }

  return {rx, ry, bx, by};
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  queue<tuple<int, int, int, int>> q;
  int height, width, tries = 0, rx, ry, bx, by, ex, ey;
  bool escaped = false;
  cin >> height >> width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        ry = i, rx = j;
      } else if (board[i][j] == 'B') {
        by = i, bx = j;
      } else if (board[i][j] == 'O') {
        ey = i, ex = j;
      }
    }
  }

  q.emplace(rx, ry, bx, by);
  visited[rx][ry][bx][by] = true;

  for (; tries < 11 && !escaped; tries++) {
    int nq = q.size();

    while (nq-- && !escaped) {
      int rtx, rty, btx, bty;
      tie(rtx, rty, btx, bty) = q.front();
      q.pop();

      if (btx == ex && bty == ey) continue;
      if (rtx == ex && rty == ey) {
        escaped = true;
        continue;
      }

      for (int i = 0; i < 4; i++) {
        int rnx, rny, bnx, bny;
        tie(rnx, rny, bnx, bny) = hit_wall(rtx, rty, btx, bty, i);

        if (visited[rnx][rny][bnx][bny]) continue;
        
        q.emplace(rnx, rny, bnx, bny);
        visited[rnx][rny][bnx][bny] = true;
      }
    }
  }

  cout << (escaped ? tries - 1 : -1);

  return 0;
}
