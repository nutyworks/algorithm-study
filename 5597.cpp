#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  vector<int> a(31, 1);

  for (int i = 0; i < 28; i++) {
    int b;
    cin >> b;
    a[b] = 0;
  }

  for (int i = 1; i <= 30; i++) {
    if (a[i]) cout << i << '\n';
  }

  return 0;
}
