// Written by lemonajoc @ 7/23/2023, 12:33:19 PM
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> t;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);

  int n, cnt = 0;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;
    t.emplace_back(a, b);
  }

  sort(t.begin(), t.end(),
      [](const pair<int, int> &a, const pair<int, int> &b) {

        if (a.second == b.second) {
          return a.first < b.first;
        } else {
          return a.second < b.second;
        }

        return true;
      });

  int end = 0;

  for (auto [a, b] : t) {
    if (a >= end) {
      cnt++;
      end = b;
    }
  }

  cout << cnt;

  return 0;
}
