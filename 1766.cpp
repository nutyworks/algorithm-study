// Written by lemonajoc @ 7/22/2023, 12:58:44 PM
#include <bits/stdc++.h>

using namespace std;

int parents[32001];
vector<int> childss[32001];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, r;
  cin >> n >> m;
  r = n;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    parents[b]++;
    childss[a].push_back(b);
  }

  while (r) {
    for (int i = 1; i <= n; i++) {
      if (parents[i]) continue;

      for (int child : childss[i]) {
        parents[child]--;
      }

      cout << i << ' ';
      parents[i] = -1;
      r--;

      break;
    }
  }

  return 0;
}
