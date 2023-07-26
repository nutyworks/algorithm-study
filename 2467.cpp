// Written by lemonajoc @ 7/22/2023, 1:23:20 PM
#include <bits/stdc++.h>

using namespace std;

int aq[100000];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, ms, me, is, ie, minv = 0x7fffffff;
  cin >> n;

  ms = is = 0;
  me = ie = n - 1;

  for (int i = 0; i < n; i++) {
    cin >> aq[i];
  }

  minv = abs(aq[is] + aq[ie]);

  while (is + 1 < ie) {
    int a = abs(aq[is + 1] + aq[ie]), b = abs(aq[is] + aq[ie - 1]);

    if (a < b) is++;
    else ie--;

    if (minv > abs(aq[is] + aq[ie])) {
      minv = abs(aq[is] + aq[ie]);
      ms = is;
      me = ie;
    }
  }

  cout << aq[ms] << ' ' << aq[me];

  return 0;
}
