#include <iostream>
#include <cstdlib>
#include <queue>

#define mz(x, y, m) maze[(y) * (m) + (x)]

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, m, maze[10000] = {};

  cin >> n >> m;

  for (int i = 0; i < n * m; i++) {
    char c;
    cin >> c;
    maze[i] = c == '1';
  }

  int dst = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  mz(0, 0, m) = 2;

  while (!q.empty()) {
    dst++;
    int nq = q.size();
    // cout << dst << ", nq=" << nq << '\n';
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < m; j++) {
    //     cout << mz(j, i, m);
    //   }
    //   cout << '\n';
    // }
    for (int i = 0; i < nq; i++) {
      auto pos = q.front();
      int x = pos.first, y = pos.second;
      q.pop();

      // cout << "(" << x << ", " << y << ") ";
      if (x == m - 1 && y == n - 1) {
        cout << dst;
        return 0;
      }


      if (x > 0 && mz(x - 1, y, m) == 1) {
        q.push(make_pair(x - 1, y));
        mz(x - 1, y, m) = 2;
      }
      if (x < m - 1 && mz(x + 1, y, m) == 1) {
        q.push(make_pair(x + 1, y));
        mz(x + 1, y, m) = 2;
      }
      if (y > 0 && mz(x, y - 1, m) == 1) {
        q.push(make_pair(x, y - 1));
        mz(x, y - 1, m) = 2;
      }
      if (y < n - 1 && mz(x, y + 1, m) == 1) {
        q.push(make_pair(x, y + 1));
        mz(x, y + 1, m) = 2;
      }
    }
    // cout << "\n\n";
  }

  cout << dst;

	return 0;
}
