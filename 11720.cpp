#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, sum = 0;
	char c;

	cin >> n;

	while (n--) {
		cin >> c;
		sum += c - '0';
	}

	cout << sum;

	return 0;
}
