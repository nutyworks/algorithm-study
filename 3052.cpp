#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n = 10, rem[42] = {}, count = 0;

	while (n--) {
		int a;
		cin >> a;
		rem[a % 42] = 1;
	}

	n = 42;
	while (n--) {
		count += rem[n];
	}

	cout << count;

	return 0;
}
