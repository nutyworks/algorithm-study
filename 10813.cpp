#include <bits/stdc++.h>

using namespace std;

int bs[101];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  for (int i = 1; i <= 100; i++) {
    bs[i] = i;
  }

  int n, m;
  cin >> n >> m;

  while (m--) {
    int i, j, t;
    cin >> i >> j;
    t = bs[i];
    bs[i] = bs[j];
    bs[j] = t;
  }

  for (int i = 1; i <= n; i++) cout << bs[i] << ' ';

  return 0;
}
