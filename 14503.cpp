// Written by lemonajoc @ 7/17/2023, 10:14:35 PM
#include <bits/stdc++.h>

using namespace std;

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int room[50][50];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
  int height, width, r, c, d, cnt = 0;
  cin >> height >> width >> r >> c >> d;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> room[i][j];
    }
  }

  while (true) {
    if (room[r][c] == 0) {
      room[r][c] = 2;
      cnt++;
    }
    if (room[r - 1][c] == 0 || room[r + 1][c] == 0 || room[r][c - 1] == 0 || room[r][c + 1] == 0) {
      d = (d + 3) % 4;
      if (room[r + dr[d]][c + dc[d]] == 0) {
        r += dr[d];
        c += dc[d];
      }
    } else {
      if (room[r - dr[d]][c - dc[d]] != 1) {
        r -= dr[d];
        c -= dc[d];
        continue;
      } else {
        break;
      }
    }
  }

  cout << cnt;

	return 0;
}
