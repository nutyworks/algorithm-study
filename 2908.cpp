#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a, b, ra, rb;
	cin >> a >> b;

	ra = a % 10 * 100 + a / 10 % 10 * 10 + a / 100;
	rb = b % 10 * 100 + b / 10 % 10 * 10 + b / 100;

	cout << (ra > rb ? ra : rb);

	return 0;
}
