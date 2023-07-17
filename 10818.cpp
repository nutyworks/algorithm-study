#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, min = 1e9, max = -1e9;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		min = min > a ? a : min;
		max = max < a ? a : max;
	}

	cout << min << ' ' << max;

	return 0;
}
