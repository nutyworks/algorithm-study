// Written by lemonajoc @ 7/23/2023, 1:11:04 PM
#include <bits/stdc++.h>

long long sumtree[2097152];

using namespace std;

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

long long _partial_sum(int start, int end, int node, int l, int r) {
  int nl = l + (r - l + 1) / 2;
  int nr = r - (r - l + 1) / 2;

  if (start > end) return 0;

  if (l == start && r == end) {
    return sumtree[node];
  }

  return _partial_sum(start, end < nr ? end : nr, left(node), l, nr) 
    + _partial_sum(nl > start ? nl : start, end, right(node), nl, r);
}

long long partial_sum(int start, int end) {
  return _partial_sum(start, end, 1, 1, 1048576);
}

void _update(int idx, long long x, int node, int l, int r) {
  int nl = l + (r - l + 1) / 2;
  int nr = r - (r - l + 1) / 2;

  if (l == r) {
    sumtree[node] = x;
    return;
  }

  if (idx >= nl) _update(idx, x, right(node), nl, r);
  else if (idx <= nr) _update(idx, x, left(node), l, nr);

  sumtree[node] = sumtree[left(node)] + sumtree[right(node)];
}

void update(int idx, long long x) {
  _update(idx, x, 1, 1, 1048576);
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    long long num;
    cin >> num;
    update(i, num);
  }

  for (int i = 0; i < m + k; i++) {
    long long a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      update(b, c);
    } else if (a == 2) {
      cout << partial_sum(b, c) << '\n';
    }
  }

  return 0;
}
