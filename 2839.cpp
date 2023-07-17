#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;

	cin >> n;

	for (int i = 0; i <= n / 3; i++) {
		int remaining = n - i * 3;
		if (remaining % 5 == 0) {
			cout << (remaining / 5 + i);

			return 0;
		}
	}

	cout << -1;

	return 0;
}
