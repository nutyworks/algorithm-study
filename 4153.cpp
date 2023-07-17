#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		if (a > c) swap(a, c);
		if (b > c) swap(b, c);

		if (a * a + b * b == c * c) {
			cout << "right\n";
		} else {
			cout << "wrong\n";
		}
	}

	return 0;
}
