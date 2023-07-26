// Written by lemonajoc @ 7/22/2023, 1:07:38 AM
#include <bits/stdc++.h>

using namespace std;

int calc_buildtime(vector<int> parentss[], int buildtime[], int memo[], int building) {
  int maxtime = 0;

  if (memo[building] != -1) return memo[building];

  for (int parent : parentss[building]) {
    maxtime = max(maxtime, calc_buildtime(parentss, buildtime, memo, parent));
  }

  return memo[building] = maxtime + buildtime[building];
}

void acmcraft() {
  queue<int> q;
  vector<int> parentss[1001] = {};
  int buildtime[1001] = {}, memo[1001], n, k, w;

  for (int i = 1; i <= 1000; i++) memo[i] = -1;

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> buildtime[i];
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    parentss[b].push_back(a);
  }
  cin >> w;
  
  cout << calc_buildtime(parentss, buildtime, memo, w) << '\n';
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    acmcraft();
  }

  return 0;
}
