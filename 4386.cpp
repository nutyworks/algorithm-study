// Written by lemonajoc @ 7/22/2023, 8:44:47 PM
#include <bits/stdc++.h>

using namespace std;

typedef tuple<double, int, int> star;

int roots[100], ranks[100];

int find(int x) {
  return roots[x] == x ? x : roots[x] = find(roots[x]);
}

void _union(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y) return;

  if (ranks[x] < ranks[y]) {
    roots[x] = y;
  } else {
    roots[y] = x;

    if (ranks[x] == ranks[y]) {
      ranks[x]++;
    }
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  priority_queue<star, vector<star>, greater<star>> edges;
  double x[100], y[100], len = .0;
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    roots[i] = i;
    ranks[i] = 0;
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.emplace(sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)), i, j);
    }
  }

  while (!edges.empty()) {
    auto [w, u, v] = edges.top();
    edges.pop();

    if (find(u) != find(v)) {
      _union(u, v);
      len += w;
    }
  }

  cout << len;

  return 0;
}
