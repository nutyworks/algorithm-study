// Written by lemonajoc @ 7/23/2023, 3:02:53 PM
#include <bits/stdc++.h>

using namespace std;

pair<int, int> mmtree[262144]; // min, max

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

pair<int, int> _partial_min_max(int node, int start, int end, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (start > end) return {0x7fffffff, 0x80000000};
  if (start == l && end == r) return mmtree[node];

  auto [ln, lx] = _partial_min_max(left(node), start, min(end, nr), l, nr);
  auto [rn, rx] = _partial_min_max(right(node), max(start, nl), end, nl, r);

  return {min(ln, rn), max(lx, rx)};
}

pair<int, int> partial_min_max(int start, int end) {
  return _partial_min_max(1, start, end, 1, 131072);
}

void _update(int node, int target, int value, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (l == r) {
    mmtree[node] = {value, value};
    return;
  }

  if (target < nl) _update(left(node), target, value, l, nr);
  else _update(right(node), target, value, nl, r);

  int ln = mmtree[left(node)].first,
      rn = mmtree[right(node)].first, 
      lx = mmtree[left(node)].second, 
      rx = mmtree[right(node)].second;

  if (!ln) ln = 0x7fffffff;
  if (!rn) rn = 0x7fffffff;
  if (!lx) lx = 0x80000000;
  if (!rx) rx = 0x80000000;

  mmtree[node] = {min(ln, rn), max(lx, rx)};
}

void update(int idx, int value) {
  _update(1, idx, value, 1, 131072);
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    update(i, a);
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    auto [mn, mx] = partial_min_max(a, b);
    cout << mn << ' ' << mx << '\n';
  }
  
  return 0;
}
