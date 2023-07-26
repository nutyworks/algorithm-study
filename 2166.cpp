// Written by lemonajoc @ 7/22/2023, 8:22:01 PM
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int x[10000], y[10000], n;
  double area = 0.;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i < n - 1; i++) {
    area += (long long) x[i] * y[i + 1] - (long long) x[i + 1] * y[i];
  }
  area += (long long) x[n - 1] * y[0] - (long long) x[0] * y[n - 1];

  printf("%.1lf", 0.5 * abs(area));

  return 0;
}
