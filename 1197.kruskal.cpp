#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef tuple<int, short, short> tiss;

short roots[10001];
short ranks[10001];

short find(short x) {
  return roots[x] == x ? x : roots[x] = find(roots[x]);
}

void _union(short x, short y) {
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

  for (int i = 1; i <= 10000; i++) {
    roots[i] = i;
    ranks[i] = 0;
  }

  priority_queue<tiss, vector<tiss>, greater<tiss>> edges;
  int nv, ne, sumw = 0;
  cin >> nv >> ne;

  for (int i = 0; i < ne; i++) {
    int w, u, v;
    cin >> u >> v >> w;
    edges.emplace(w, u, v);
  }

  while (!edges.empty()) {
    int w, u, v;
    tie(w, u, v) = edges.top();
    edges.pop();

    if (find(u) != find(v)) {
      _union(u, v);
      sumw += w;
    }
  }

  cout << sumw;

  return 0;
}
