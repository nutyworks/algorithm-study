// Written by lemonajoc @ 7/23/2023, 8:45:37 PM
#include <bits/stdc++.h>

using namespace std;

int segtree[2097152];

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

int _product(int node, int start, int end, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (start > end) return 1;
  if (l == start && r == end) return segtree[node];

  return ((long long) _product(left(node), start, min(end, nr), l, nr) 
          * (long long) _product(right(node), max(start, nl), end, nl, r)) % 1000000007;
}

inline int product(int start, int end) {
  return _product(1, start, end, 1, 1048576);
}

void _update(int node, int target, int value, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (l == r) {
    segtree[node] = value;
    return;
  }

  if (target < nl) _update(left(node), target, value, l, nr);
  else _update(right(node), target, value, nl, r);

  segtree[node] = ((long long) segtree[left(node)] * (long long) segtree[right(node)]) % 1000000007;
}

inline void update(int idx, int value) {
  _update(1, idx, value, 1, 1048576);
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  fill(segtree, segtree + 2097152, 1);
  
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    update(i, a);
  }

  for (int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      update(b, c);
    } else {
      cout << product(b, c) << '\n';
    }
  }

  return 0;
}
