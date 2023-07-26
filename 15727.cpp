#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n;
  cin >> n;
  cout << n / 5 + !!(n % 5);

  return 0;
}
