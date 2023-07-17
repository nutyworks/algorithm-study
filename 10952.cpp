#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a && b) {
			cout << (a + b) << '\n';
		} else {
			break;
		}
	}

	return 0;
}
