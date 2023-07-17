#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << (a + b) << '\n';
	}

	return 0;
}
