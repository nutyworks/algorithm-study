// Written by lemonajoc @ 7/23/2023, 6:34:01 AM
#include <bits/stdc++.h>

using namespace std;

bool gates_used[262144];

inline int left(int node) {
  return node * 2;
}

inline int right(int node) {
  return node * 2 + 1;
}

bool mark(int cur, int maxgate, int leftmost, int rightmost) {
  bool ret = false;
  int nl = leftmost + (rightmost - leftmost + 1) / 2, nr = rightmost - (rightmost - leftmost + 1) / 2;

  if (leftmost == rightmost) {
    gates_used[cur] = true;
    return true;
  }
  if (nl <= maxgate && !gates_used[right(cur)]) ret = mark(right(cur), maxgate, nl, rightmost);

  if (!ret && !gates_used[left(cur)]) ret = mark(left(cur), maxgate, leftmost, nr);

  if (gates_used[left(cur)] && gates_used[right(cur)]) gates_used[cur] = true;

  return ret;
}

void mark_closed(int cur, int mingate, int leftmost, int rightmost) {
  int nl = leftmost + (rightmost - leftmost + 1) / 2, nr = rightmost - (rightmost - leftmost + 1) / 2;

  if (leftmost >= mingate) {
    gates_used[cur] = true;
    return;
  }

  mark_closed(right(cur), mingate, nl, rightmost);
  if (nr >= mingate) mark_closed(left(cur), mingate, leftmost, nr);

  if (gates_used[left(cur)] && gates_used[right(cur)]) gates_used[cur] = true;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int g, p, cnt = 0;
  cin >> g >> p;

  mark_closed(1, g + 1, 1, 131072);

  while (p--) {
    int gi;
    cin >> gi;

    if (mark(1, gi, 1, 131072)) cnt++;
    else break;
  }

  cout << cnt;

  return 0;
}
