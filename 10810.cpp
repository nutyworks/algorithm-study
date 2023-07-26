#include <bits/stdc++.h>

using namespace std;

int bs[100];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a - 1; i < b; i++) {
      bs[i] = c;
    }
  }

  for (int i = 0; i < n; i++) cout << bs[i] << ' ';

  return 0;
}
