#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int DX[] = { -1, 1, 0, 0, 0, 0 };
int DY[] = { 0, 0, -1, 1, 0, 0 };
int DZ[] = { 0, 0, 0, 0, -1, 1 };

bool is_valid_pos(int x, int y, int z, int mx, int my, int mz) {
  return x >= 0 && x < mx && y >= 0 && y < my && z >= 0 && z < mz;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  queue<tuple<int, int, int>> q;

  int xl, yl, zl, box[100][100][100], t;
  cin >> xl >> yl >> zl;

  for (int zi = 0; zi < zl; zi++) {
    for (int yi = 0; yi < yl; yi++) {
      for (int xi = 0; xi < xl; xi++) {
        cin >> t;
        box[zi][yi][xi] = t;

        if (t == 1) {
          q.push(make_tuple(xi, yi, zi));
        }
      }
    }
  }

  int days_elapsed = -1;

  while (!q.empty()) {
    int nq = q.size();

    while (nq--) {
      int x, y, z;
      tie(x, y, z) = q.front();
      q.pop();

      for (int i = 0; i < 6; i++) {
        if (
          is_valid_pos(x + DX[i], y + DY[i], z + DZ[i], xl, yl, zl)
          && box[z + DZ[i]][y + DY[i]][x + DX[i]] == 0
        ) {
          q.push(make_tuple(x + DX[i], y + DY[i], z + DZ[i]));
          box[z + DZ[i]][y + DY[i]][x + DX[i]] = 1;
        }
      }
    }

    ++days_elapsed;
  }

  for (int zi = 0; zi < zl; zi++) {
    for (int yi = 0; yi < yl; yi++) {
      for (int xi = 0; xi < xl; xi++) {
        if (box[zi][yi][xi] == 0) {
          cout << -1;
          return 0;
        }
      }
    }
  }

  cout << days_elapsed;

	return 0;
}
