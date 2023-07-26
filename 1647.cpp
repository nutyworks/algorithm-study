// Written by lemonajoc @ 7/22/2023, 5:59:55 PM
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> edge; // weight, u, v

int roots[100001], ranks[100001];

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
  
  priority_queue<edge, vector<edge>, greater<edge>> edges;

  int n, m, max_edge_weight = 0, total_edge_weight = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.emplace(w, u, v);
  }

  for (int i = 1; i <= 100000; i++) {
    roots[i] = i;
    ranks[i] = 0;
  }

  while (!edges.empty()) {
    auto [w, u, v] = edges.top();
    edges.pop();

    if (find(u) != find(v)) {
      _union(u, v);

      total_edge_weight += w;
      max_edge_weight = max(max_edge_weight, w);
    }
  }

  cout << total_edge_weight - max_edge_weight;

  return 0;
}
