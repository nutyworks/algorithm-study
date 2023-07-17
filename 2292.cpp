#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	double n;

	cin >> n;
	cout << ceil((3 + sqrt(9-12*(1-n)))/6);

	return 0;
}