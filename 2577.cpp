#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a, b, c, digits[10] = {};
	cin >> a >> b >> c;
	
	a = a * b * c;

	for (; a; a /= 10) {
		digits[a % 10]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << digits[i] << '\n';
	}

	return 0;
}
