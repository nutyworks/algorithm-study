#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int total, n, a, b, sum = 0;
  cin >> total >> n;

  while (n--) {
    cin >> a >> b;

    sum += a * b;
  }

  cout << (total == sum ? "Yes" : "No");

  return 0;
}
