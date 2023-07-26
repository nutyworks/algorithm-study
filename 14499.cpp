// Written by lemonajoc @ 7/17/2023, 1:07:56 PM
#include <bits/stdc++.h>

using namespace std;

#define TOP 0
#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
#define BOTTOM 5

const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};

int board[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0};

pair<int, int> move_dice(int direction, int x, int y, int width, int height) {
  int t = 0;

  int nx = x + dx[direction];
  int ny = y + dy[direction];

  if (nx < 0 || ny < 0 || nx >= width || ny >= height) return {x, y};

  switch (direction) {
  case EAST:
    t = dice[EAST];
    dice[EAST] = dice[TOP];
    dice[TOP] = dice[WEST];
    dice[WEST] = dice[BOTTOM];
    dice[BOTTOM] = t;
    break;
  case WEST:
    t = dice[WEST];
    dice[WEST] = dice[TOP];
    dice[TOP] = dice[EAST];
    dice[EAST] = dice[BOTTOM];
    dice[BOTTOM] = t;
    break;
  case NORTH:
    t = dice[NORTH];
    dice[NORTH] = dice[TOP];
    dice[TOP] = dice[SOUTH];
    dice[SOUTH] = dice[BOTTOM];
    dice[BOTTOM] = t;
    break;
  case SOUTH:
    t = dice[SOUTH];
    dice[SOUTH] = dice[TOP];
    dice[TOP] = dice[NORTH];
    dice[NORTH] = dice[BOTTOM];
    dice[BOTTOM] = t;
    break;
  }
  
  if (board[ny][nx] == 0) {
    board[ny][nx] = dice[BOTTOM];
  } else {
    dice[BOTTOM] = board[ny][nx];
    board[ny][nx] = 0;
  }

  cout << dice[TOP] << '\n';

  return {nx, ny};
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, x, y, k;
  cin >> n >> m >> y >> x >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  while (k--) {
    int direction;
    cin >> direction;
    tie(x, y) = move_dice(direction, x, y, m, n);
  }

  return 0;
}
