#include <iostream>

using namespace std;

int ctable[30][30];

int nCr(int n, int r) {
	if (n == r || r == 0) return 1;
	else if (ctable[n][r] > 0) return ctable[n][r];
	else return ctable[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int floor, ho;
		cin >> floor >> ho;

		int n = floor + ho, r = floor + 1;
		cout << nCr(n, r) << '\n';
	}

	return 0;
}
