#include <bits/stdc++.h>

using namespace std;

const int normal[6] = { 1, 1, 2, 2, 2, 8 };

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  for (int i = 0; i < 6; i++) {
    int a;
    cin >> a;
    cout << normal[i] - a << ' ';
  }

  return 0;
}
