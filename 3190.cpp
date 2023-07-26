// Written by lemonajoc @ 7/17/2023, 10:31:18 PM
#include <bits/stdc++.h>

using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};

int board[100][100];
queue<pair<int, char>> snake_rotations;
queue<pair<int, int>> snake_positions;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, k, l, sd = 0, t = 0;
  cin >> n >> k;

  snake_positions.emplace(0, 0);
  board[0][0] = 1;

  while (k--) {
    int ar, ac;
    cin >> ar >> ac;
    board[ar - 1][ac - 1] = 2;
  }

  cin >> l;

  while (l--) {
    int rt;
    char rd;
    cin >> rt >> rd;
    snake_rotations.emplace(rt, rd);
  }

  while (true) {
    t++;

    int nr, nc;
    tie(nr, nc) = snake_positions.back();

    nr += dr[sd];
    nc += dc[sd];

    if (nr < 0 || nc < 0 || nr >= n || nc >= n) break;
    if (board[nr][nc] == 1) break;

    if (board[nr][nc] != 2) {
      int br, bc;
      tie(br, bc) = snake_positions.front();
      snake_positions.pop();
      board[br][bc] = 0;
    }

    if (!snake_rotations.empty()) {
      int rt;
      char rd;
      tie(rt, rd) = snake_rotations.front();
      if (rt == t) {
        snake_rotations.pop();
        if (rd == 'L') sd = (sd + 3) % 4;
        else if (rd == 'D') sd = (sd + 1) % 4;
      }
    }

    snake_positions.emplace(nr, nc);
    board[nr][nc] = 1;
  }

  cout << t;

  return 0;
}
