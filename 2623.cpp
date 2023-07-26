// Written by lemonajoc @ 7/22/2023, 9:52:08 PM
#include <bits/stdc++.h>

using namespace std;

int parents[1001];
vector<int> childss[1001];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, remaining;
  vector<int> seq;
  cin >> n >> m;
  remaining = n;

  for (int i = 0; i < m; i++) {
    int cs, pv;
    cin >> cs;
    if (cs > 0) cin >> pv;
    for (int j = 0; j < cs - 1; j++) {
      int c;
      cin >> c;
      parents[c]++;
      childss[pv].push_back(c);
      pv = c;
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << i << " has " << parents[i] << " parent(s) and childs are: ";
  //   for (int child : childss[i]) cout << child << ' ';
  //   cout << '\n';
  // }

  int prev_remaining = 0;

  while (remaining) {
    if (prev_remaining == remaining) {
      cout << '0';
      return 0;
    }

    prev_remaining = remaining;
    
    for (int i = 1; i <= n; i++) {
      if (parents[i]) continue;

      seq.push_back(i);

      for (int child : childss[i]) {
        parents[child]--;
      }

      parents[i] = -1;
      remaining--;
      break;
    }
  }

  for (int i : seq) {
    cout << i << '\n';
  }

  return 0;
}
