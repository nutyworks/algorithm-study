// Written by lemonajoc @ 7/21/2023, 11:44:20 PM
#include <bits/stdc++.h>

using namespace std;

int parents[32001];
vector<short> childss[32001];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  queue<int> q;
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    parents[b]++;
    childss[a].push_back(b);
  }

  for (int i = 1; i <= n; i++) {
    if (!parents[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int i = q.front();
    q.pop();
    if (!parents[i]) {
      cout << i << ' ';
      parents[i] = -1;

      for (short child : childss[i]) {
        parents[child]--;

        if (!parents[child]) {
          q.push(child);
        }
      }
    }
  }

  return 0;
}
