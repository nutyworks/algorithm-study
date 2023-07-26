// Written by lemonajoc @ 7/22/2023, 2:00:37 AM
#include <bits/stdc++.h>

using namespace std;

int primes[283146] = { 2, };

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int p = 0, istart = 0, iend = 0, cnt = 0, s = 0, n;
  for (int i = 2; i < 4000000; i++) {
    bool isprime = true;
    for (int j = 0; primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        isprime = false;
        break;
      }
    }
    if (isprime) primes[p++] = i;
  }

  cin >> n;

  s = 2;

  while (iend != 283146 && primes[iend] <= n) {
    if (s < n || istart > iend) {
      s += primes[++iend];
    } else {
      if (s == n) cnt++;
      s -= primes[istart++];
    }
  }

  cout << cnt;

  return 0;
}
