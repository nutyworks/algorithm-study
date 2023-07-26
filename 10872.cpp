#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, product = 1;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    product *= i;
  }

  cout << product;

  return 0;
}
