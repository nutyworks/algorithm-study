#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int DX[] = { -1, 1, 0, 0 };
const int DY[] = { 0, 0, -1, 1 };

pair<int, int> find_unclassified_baechu(int baechumap[50][50], int xsize, int ysize) {
  for (int y = 0; y < ysize; y++) {
    for (int x = 0; x < xsize; x++) {
      if (baechumap[y][x] == 1) {
        return make_pair(x, y);
      }
    }
  }

  return make_pair(-1, -1);
}

bool is_valid_position(int x, int y, int xsize, int ysize) {
  return x >= 0 && x < xsize && y >= 0 && y < ysize;
}

void bfs_baechu(int baechumap[50][50], int xsize, int ysize, pair<int, int> initial_pos) {
  queue<pair<int, int>> q;
  q.push(initial_pos);
  int x, y;
  tie(x, y) = initial_pos;
  baechumap[y][x] = 0;

  while (!q.empty()) {
    tie(x, y) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (is_valid_position(x + DX[i], y + DY[i], xsize, ysize) && baechumap[y + DY[i]][x + DX[i]] == 1) {
        baechumap[y + DY[i]][x + DX[i]] = 0;
        q.push(make_pair(x + DX[i], y + DY[i]));
      }
    }
  }
}

void reset_baechu(int baechumap[50][50]) {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      baechumap[i][j] = 0;
    }
  }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int xsize, ysize, k, baechu[50][50], testcases;

  cin >> testcases;

  while (testcases--) {
    reset_baechu(baechu);

    cin >> xsize >> ysize >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      baechu[y][x] = 1;
    }

    vector<int> area_per_danji;
    int nworm = 0;

    while (true) {
      auto pos = find_unclassified_baechu(baechu, xsize, ysize);

      if (pos.first == -1) { break; }
      ++nworm;

      bfs_baechu(baechu, xsize, ysize, pos);
    }

    cout << nworm << '\n';
  }

	return 0;
}
