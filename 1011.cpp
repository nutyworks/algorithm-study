#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;

	cin >> n;

	while (n--) {
		double x, y;
		cin >> x >> y;
		cout << ceil(-1 + 2 * sqrt(y-x)) << '\n';
	}

	return 0;
}