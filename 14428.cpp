// Written by lemonajoc @ 7/23/2023, 9:48:37 PM
#include <bits/stdc++.h>

using namespace std;

pair<int, int> segtree[262144]; // idx. value

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

pair<int, int> _query(int node, int start, int end, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (start > end) return {0, 0x7fffffff};
  if (start == l && end == r) return segtree[node];

  auto [li, lv] = _query(left(node), start, min(nr, end), l, nr);
  auto [ri, rv] = _query(right(node), max(nl, start), end, nl, r);

  if (lv <= rv) {
    return {li, lv};
  } else {
    return {ri, rv};
  }
}

inline int query(int start, int end) {
  return _query(1, start, end, 1, 131072).first;
}

void _update(int node, int target, int value, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (l == r) {
    segtree[node] = {target, value};
    return;
  }

  if (target < nl) _update(left(node), target, value, l, nr);
  else _update(right(node), target, value, nl, r);

  auto [li, lv] = segtree[left(node)];
  auto [ri, rv] = segtree[right(node)];

  if (lv == 0) segtree[node] = segtree[right(node)];
  if (rv == 0) segtree[node] = segtree[left(node)];

  if (lv <= rv) {
    segtree[node] = segtree[left(node)];
  } else {
    segtree[node] = segtree[right(node)];
  }
}

void update(int idx, int value) {
  _update(1, idx, value, 1, 131072);
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    update(i, a);
  }

  cin >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      update(b, c);
    } else {
      cout << query(b, c) << '\n';
    }
  }

  return 0;
}
