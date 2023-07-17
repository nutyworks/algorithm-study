#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int DX[] = { -1, 1, 0, 0 };
const int DY[] = { 0, 0, -1, 1 };

pair<int, int> find_unclassified_danji(int danjimap[25][25], int size) {
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (danjimap[y][x] == 0) {
        return make_pair(x, y);
      }
    }
  }

  return make_pair(-1, -1);
}

bool is_valid_position(int x, int y, int size) {
  return x >= 0 && x < size && y >= 0 && y < size;
}

int bfs_danji(int danjimap[25][25], int size, pair<int, int> initial_pos) {
  queue<pair<int, int>> q;
  q.push(initial_pos);
  int x, y, count = 0;
  tie(x, y) = initial_pos;
  danjimap[y][x] = -1;

  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (is_valid_position(x + DX[i], y + DY[i], size) && danjimap[y + DY[i]][x + DX[i]] == 0) {
        danjimap[y + DY[i]][x + DX[i]] = -1;
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
	
  int n, danji[25][25];

  cin >> n;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      char a;
      cin >> a;
      danji[y][x] = a - 49;
    }
  }

  vector<int> area_per_danji;
  int ndanji = 0;

  while (true) {
    auto pos = find_unclassified_danji(danji, n);

    if (pos.first == -1) { break; }
    ++ndanji;

    int blocks = bfs_danji(danji, n, pos);
    area_per_danji.push_back(blocks);
  }

  sort(area_per_danji.begin(), area_per_danji.end());
  
  cout << ndanji << '\n';

  for (int area : area_per_danji) {
    cout << area << '\n';
  }

	return 0;
}
