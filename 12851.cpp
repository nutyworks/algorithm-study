#include <iostream>
#include <queue>

using namespace std;

#define mark(x) do { \
  if (t[(x)] == 0) { \
    bq.push((x)); \
  } \
  if (t[(x)] <= 0) { \
    t[x] -= hits_before; \
  } \
  if ((x) == n) hit = 1; \
} while (0)

int t[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, k;
  queue<int> bq;

  cin >> n >> k;

  if (k == n) {
    cout << "0\n1";
    return 0;
  }

  bq.push(k);
  t[k] = 1;
  int steps = 0;

  while (!bq.empty()) {
    steps++;

    int size = bq.size();
    int hit = 0;

    while (size--) {
      int i = bq.front();
      int hits_before = t[i];
      bq.pop();

      if (i % 2 == 0 && i > 0) {
        mark(i / 2);
      }
      mark(i + 1);
      mark(i - 1);
    }

    size = bq.size();

    while (size--) {
      int i = bq.front();
      bq.pop();
      t[i] = -t[i];
      bq.push(i);
    }

    if (hit) {
      cout << steps << '\n' << t[n];
      break;
    }
  }

	return 0;
}
