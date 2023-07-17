#include <iostream>

using namespace std;

int isren3of6s(int n) {
	int ren = 0;

	for (; n; n /= 10) {
		if (n % 10 == 6) {
			ren++;

			if (ren == 3) {
				return 1;
			}
		} else {
			ren ^= ren;
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, eviln = 665;
	cin >> n;

	while (n) {
		eviln++;
		if (isren3of6s(eviln)) {
			n--;
		}
	}

	cout << eviln;

	return 0;
}
