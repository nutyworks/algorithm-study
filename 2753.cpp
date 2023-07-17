#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int y;
	cin >> y;

	cout << (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 1 : 0);

	return 0;
}
