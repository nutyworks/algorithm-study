#include <iostream>

using namespace std;

int isprime(int n) {
	if (n == 1) return 0;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}

	return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, count = 0;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		count += isprime(a);
	}

	cout << count;

	return 0;
}
