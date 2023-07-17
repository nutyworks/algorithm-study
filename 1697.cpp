#include <iostream>
#include <queue>

using namespace std;

int t[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, k;
  queue<int> bq;

  cin >> n >> k;

  if (k < n) {
    cout << n - k;
    return 0;
  }

  bq.push(k);
  t[k] = 1;

  while (!bq.empty()) {
    int i = bq.front();
    int ti = t[i];
    bq.pop();

    if ((i & 1) == 0 && i && !t[i / 2]) {
      bq.push(i / 2);
      t[i / 2] = ti + 1;
    }
    if (i > 0 && !t[i - 1]) {
      bq.push(i - 1);
      t[i - 1] = ti + 1;
    }
    if (i < 100000 && !t[i + 1]) {
      bq.push(i + 1);
      t[i + 1] = ti + 1;
    }
  }

  cout << t[n] - 1;

	return 0;
}
