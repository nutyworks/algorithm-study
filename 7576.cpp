#include <iostream>
#include <queue>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int m, n, day = 0, empty_room = 0, nmature = 0;
	cin >> m >> n;

	int box[1000][1000] = {};
	queue<pair<int, int>> mature;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];

			if (box[i][j] == 1) {
				mature.push(make_pair(j, i));
			} else if (box[i][j] == -1) {
				empty_room++;
			}
		}
	}

	while (!mature.empty()) {
		pair<int, int> tomato = mature.front();
		nmature++;
		mature.pop();
		int x = tomato.first, y = tomato.second;
		if (x > 0 && box[y][x-1] == 0) {
			box[y][x-1] = box[y][x] + 1;
			mature.push(make_pair(x-1, y));
			day = box[y][x];
		}
		if (x < m - 1 && box[y][x+1] == 0) {
			box[y][x+1] = box[y][x] + 1;
			mature.push(make_pair(x+1, y));
			day = box[y][x];
		}
		if (y > 0 && box[y-1][x] == 0) {
			box[y-1][x] = box[y][x] + 1;
			mature.push(make_pair(x, y-1));
			day = box[y][x];
		}
		if (y < n - 1 && box[y+1][x] == 0) {
			box[y+1][x] = box[y][x] + 1;
			mature.push(make_pair(x, y+1));
			day = box[y][x];
		}
	}

	if (empty_room + nmature == n * m) {
		cout << day;
	} else {
		cout << -1;
	}

	return 0;
}