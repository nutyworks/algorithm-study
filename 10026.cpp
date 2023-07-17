#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define SIZE 100

using namespace std;

const int DX[] = { -1, 1, 0, 0 };
const int DY[] = { 0, 0, -1, 1 };

pair<int, int> find_unclassified_zone(char grid[SIZE][SIZE], int size, int traversed_mask) {
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if ((grid[y][x] & traversed_mask) == 0) {
        return make_pair(x, y);
      }
    }
  }

  return make_pair(-1, -1);
}

bool is_valid_position(int x, int y, int size) {
  return x >= 0 && x < size && y >= 0 && y < size;
}

int bfs_zone(char grid[SIZE][SIZE], int size, pair<int, int> initial_pos, int sight_mask, int traversed_mask) {
  queue<pair<int, int>> q;
  q.push(initial_pos);
  int x, y, count = 0;
  tie(x, y) = initial_pos;
  grid[y][x] |= traversed_mask;
  int color = grid[y][x] & sight_mask;

  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (is_valid_position(x + DX[i], y + DY[i], size) 
        && (grid[y + DY[i]][x + DX[i]] & traversed_mask) == 0
        && (grid[y + DY[i]][x + DX[i]] & sight_mask) == color
      ) {
        grid[y + DY[i]][x + DX[i]] |= traversed_mask;
        q.push(make_pair(x + DX[i], y + DY[i]));
      }
    }

    ++count;
  }

  return count;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n;
  char color[SIZE][SIZE];

  cin >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      char a;
      cin >> a;

      if (a == 'R') {
        color[y][x] = 0b001;
      } else if (a == 'G') {
        color[y][x] = 0b010;
      } else if (a == 'B') {
        color[y][x] = 0b111;
      }
    }
  }

  int normal_zone = 0, rg_zone = 0;

  while (true) {
    auto pos = find_unclassified_zone(color, n, 0x08);

    if (pos.first == -1) { break; }
    ++normal_zone;

    int blocks = bfs_zone(color, n, pos, 0x03, 0x08);
  }

  while (true) {
    auto pos = find_unclassified_zone(color, n, 0x10);

    if (pos.first == -1) { break; }
    ++rg_zone;

    int blocks = bfs_zone(color, n, pos, 0x04, 0x10);
  }

  cout << normal_zone << ' ' << rg_zone;

	return 0;
}
