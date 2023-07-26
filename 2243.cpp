// Written by lemonajoc @ 7/23/2023, 10:14:47 PM
#include <bits/stdc++.h>

using namespace std;

int segtree[2097152];

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

void _modify_candy(int node, int target, int diff, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;

  if (l == r) {
    segtree[node] += diff;
    return;
  }

  if (target < nl) _modify_candy(left(node), target, diff, l, nr);
  else _modify_candy(right(node), target, diff, nl, r);

  segtree[node] = segtree[left(node)] + segtree[right(node)];
}

void modify_candy(int level, int diff) {
  _modify_candy(1, level, diff, 1, 1048576);
}

int _present_candy(int node, int priority, int l, int r) {
  int nl = l + (r - l + 1) / 2, nr = r - (r - l + 1) / 2;
  
  if (node >= 1048576) return node - 1048575;

  int lv = segtree[left(node)];

  if (lv >= priority) return _present_candy(left(node), priority, l, nr);
  else return _present_candy(right(node), priority - lv, nl, r);
}

int present_candy(int priority) {
  int level = _present_candy(1, priority, 1, 1048576);
  modify_candy(level, -1);
  return level;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n;
  cin >> n;

  while (n--) {
    int a, b, c;
    cin >> a;

    if (a == 1) {
      cin >> b;
      cout << present_candy(b) << '\n';
    } else {
      cin >> b >> c;
      modify_candy(b, c);
    }
  }

  return 0;
}
