#include <iostream>

using namespace std;

int ctable[11][11];
int nCr(int n, int r) {
	if (n == r || r == 0) return 1;
	else if (ctable[n][r] > 0) return ctable[n][r];
	else return ctable[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, k;
  cin >> n >> k;

  cout << nCr(n, k);

	return 0;
}
