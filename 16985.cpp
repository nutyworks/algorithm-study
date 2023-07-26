// Written by lemonajoc @ 7/17/2023, 9:19:42 PM
#include <bits/stdc++.h>

using namespace std;

const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

unsigned int min_dst = 0xffffffff;

int maze[5][5][5];
int boards[5][5][5];
bool board_selected[5];
vector<pair<int, int>> selected;

unsigned int bfs() {
  if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return 0xffffffff;

  int dist = 0;
  bool success = false;
  queue<tuple<int, int, int>> q;

  q.emplace(0, 0, 0);
  maze[0][0][0] = 2;

  while (!q.empty()) {
    int nq = q.size();
    while (nq--) {
      int tx, ty, tz;
      tie(tx, ty, tz) = q.front();
      q.pop();

      if (tx == 4 && ty == 4 && tz == 4) {
        success = true;
        goto finish;
      }

      for (int i = 0; i < 6; i++) {
        int nx = tx + dx[i], ny = ty + dy[i], nz = tz + dz[i];

        if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
        if (maze[nz][ny][nx] != 1) continue;

        q.emplace(nx, ny, nz);
        maze[nz][ny][nx] = 2;
      }
    }
    dist++;
  }

finish:
  return success ? dist : 0xffffffff;
}

void rotate(int floor, int n) {
  for (int i = 0; i < n; i++) {
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        maze[floor][x][4 - y] |= (maze[floor][y][x] & 1) << 1;
      }
    }
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        maze[floor][y][x] >>= 1;
      }
    }
  }
}

void setup_maze() {
  for (int f = 0; f < 5; f++) {
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        maze[f][y][x] = boards[selected[f].first][y][x];
      }
    }
    rotate(f, selected[f].second);
  }
}

void bruteforce(int depth) {
  if (depth == 5) {
    setup_maze();
    unsigned int dst = bfs();
    min_dst = dst < min_dst ? dst : min_dst;
    return;
  }

  for (int i = 0; i < 5; i++) {
    if (board_selected[i]) continue;

    board_selected[i] = true;

    for (int r = 0; r < 4; r++) {
      selected.emplace_back(i, r);
      bruteforce(depth + 1);
      selected.pop_back();
    }

    board_selected[i] = false;
  }
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
  for (int f = 0; f < 5; f++) {
    for (int y = 0; y < 5; y++) {
      for (int x = 0; x < 5; x++) {
        cin >> boards[f][y][x];
      }
    }
  }

  bruteforce(0);

  cout << (int) min_dst;

	return 0;
}
