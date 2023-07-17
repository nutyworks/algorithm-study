#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int h, m;
	cin >> h >> m;

	if (m < 45) {
		cout << ((h + 23) % 24) << ' ' << (m + 15);
	} else {
		cout << h << ' ' << m - 45;
	}

	return 0;
}
