#include <bits/stdc++.h>

using namespace std;

int mat[100][100];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      cout << mat[i][j] + a << ' ';
    }
    cout << '\n';
  }

  return 0;
}
