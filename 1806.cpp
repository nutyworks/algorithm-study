// Written by lemonajoc @ 7/22/2023, 12:27:20 AM
#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, s, istart = 0, iend = 0, sum, minlen = 0x7fffffff;
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sum = a[0];

  while (iend != n) {
    if (sum < s || istart > iend) {
      sum += a[++iend];
    } else {
      minlen = min(minlen, iend - istart + 1);
      sum -= a[istart++];
    }
  }

  cout << (minlen == 0x7fffffff ? 0 : minlen);
 
  return 0;
}
