// Written by lemonajoc @ 7/23/2023, 9:31:09 PM
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  long long n, divisor = 2, sqrtn, phi = 1;
  vector<pair<long long, int>> factors; // base, exp
  cin >> n;

  sqrtn = sqrt(n);

  while (n != 1 && divisor <= sqrtn) {
    if (n % divisor == 0) {
      if (factors.empty() || factors.back().first != divisor)
        factors.emplace_back(divisor, 0);

      factors.back().second++;

      n /= divisor;
    } else {
      divisor++;
    }
  }

  if (n > 1) factors.emplace_back(n, 1);

  for (auto [base, exp] : factors) {
    phi *= (base - 1) * pow(base, exp - 1);
  }

  cout << phi;

  return 0;
}
