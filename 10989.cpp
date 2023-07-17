#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, t, arr[10001] = {};
	cin >> n;

	while (n--) {
		cin >> t;
		arr[t]++;
	}
	
	for (int i = 1; i <= 10000; i++) {
		int repeat = arr[i];
		while (repeat--) {
			cout << i << '\n';
		}
	}

	return 0;
}
