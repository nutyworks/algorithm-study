// Written by lemonajoc @ 7/22/2023, 8:51:08 AM
#include <bits/stdc++.h>

using namespace std;

bool pal[2001][2001];
int numbers[2001];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> numbers[i];
    pal[i][i] = 1;
    for (int j = 1; j < i; j++) {
      bool p = j + 1 == i || pal[j + 1][i - 1];
      pal[j][i] = p && numbers[i] == numbers[j];
    }
  }

  cin >> m;

  while (m--) {
    int s, e;
    cin >> s >> e;
    cout << pal[s][e] << '\n';
  }

  return 0;
}
