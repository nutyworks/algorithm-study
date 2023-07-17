#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int testcases, nfloor, width, icustomer;

	cin >> testcases;

	while (testcases--) {
		cin >> nfloor >> width >> icustomer;

		icustomer--;

		int floor = icustomer % nfloor, iroom = icustomer / nfloor;
		cout << (floor + 1) * 100 + iroom + 1 << '\n';
	}

	return 0;
}
