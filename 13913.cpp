// Written by lemonajoc @ 7/19/2023, 9:30:36 PM
#include <bits/stdc++.h>

using namespace std;

int t[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, k, moves = 0;
  queue<int> bq;

  cin >> n >> k;

  if (k < n) {
    cout << n - k << '\n';
    for (int i = n; i >= k; i--) {
      cout << i << ' ';
    }
    return 0;
  }

  bq.push(k);
  t[k] = -1;

  while (!bq.empty()) {
    int nq = bq.size();
    while (nq--) {
      int i = bq.front();
      bq.pop();

      if (i == n) {
        cout << moves << '\n';
        for (int idx = i; idx != -1; idx = t[idx]) {
          cout << idx << ' ';
        }
        return 0;
      }

      if ((i & 1) == 0 && i && !t[i / 2]) {
        bq.push(i / 2);
        t[i / 2] = i;
      }
      if (i > 0 && !t[i - 1]) {
        bq.push(i - 1);
        t[i - 1] = i;
      }
      if (i < 100000 && !t[i + 1]) {
        bq.push(i + 1);
        t[i + 1] = i;
      }
    }
    moves++;
  }


	return 0;
}
