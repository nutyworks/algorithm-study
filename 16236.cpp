#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 20
#define SPACE space[20][20]

using namespace std;

int DX[] = { -1, 1, 0, 0 };
int DY[] = { 0, 0, -1, 1 };

struct shark {
  int size;
  int pos_x;
  int pos_y;
  int fishes_eaten;
};

int get_space_info(int SPACE, shark *shark) {
  int t, n;
  cin >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> t;
      if (t == 9) {
        space[y][x] = 0;
        shark->pos_x = x;
        shark->pos_y = y;
      } else {
        space[y][x] = t;
      }
    }
  }
  return n;
}

bool is_valid_pos(int x, int y, int n) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

bool sort_y_x(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int select_edible(int SPACE, int size, shark shark, int *x, int *y) {
  // bfs it
  vector<pair<int, int> > edibles;
  queue<pair<int, int> > q;
  q.push(make_pair(shark.pos_x, shark.pos_y));
  space[shark.pos_y][shark.pos_x] |= 0x10; // traversing mask

  int distance = 0;

  while (!q.empty()) {
    int nq = q.size();

    while (nq--) {
      int x = q.front().first, y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        if (
          is_valid_pos(x + DX[i], y + DY[i], size)
          && (space[y + DY[i]][x + DX[i]] & 0x10) == 0
          && (space[y + DY[i]][x + DX[i]] & 0x0f) <= shark.size
        ) {
          q.push(make_pair(x + DX[i], y + DY[i]));
          space[y + DY[i]][x + DX[i]] |= 0x10;

          if ((space[y + DY[i]][x + DX[i]] & 0x0f) > 0 && (space[y + DY[i]][x + DX[i]] & 0x0f) < shark.size) {
            edibles.push_back(make_pair(x + DX[i], y + DY[i]));
          }
        }
      }
    }

    ++distance;

    if (edibles.size() > 0) {
      break;
    }
  }

  if (edibles.size() == 0) return -1;

  // sort by y asc, x asc
  sort(edibles.begin(), edibles.end(), sort_y_x);

  *x = edibles[0].first;
  *y = edibles[0].second;

  // reset traversing data
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      space[y][x] &= 0x0f;
    }
  }

  return distance;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int time_elapsed = 0, SPACE;
  shark shark;
  shark.size = 2;
  shark.fishes_eaten = 0;

  int n = get_space_info(space, &shark);

  int x, y, distance, total_distance = 0;
  while (~(distance = select_edible(space, n, shark, &x, &y))) {
    total_distance += distance;

    space[y][x] = 0;
    shark.pos_x = x;
    shark.pos_y = y;

    ++shark.fishes_eaten;

    if (shark.fishes_eaten == shark.size) {
      ++shark.size;
      shark.fishes_eaten = 0;
    }
  }

  cout << total_distance;

	return 0;
}
