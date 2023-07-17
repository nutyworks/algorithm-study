#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int up, down, h;
	cin >> up >> down >> h;
	cout << 1 + (h - up) / (up - down) + !!((h - up) % (up - down));

	return 0;
}
