#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n = 0;

	for (int i = 8; i--;) {
		int a;
		cin >> a;
		n = n * 10 + a;
	}

	if (n == 12345678) { cout << "ascending"; }
	else if (n == 87654321) { cout << "descending"; }
	else { cout << "mixed"; }

	return 0;
}
