#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	while (n--) {
		int repeat;
		string s;
		cin >> repeat >> s;
		for (char c : s) {
			for (int i = 0; i < repeat; i++) {
				cout << c;
			}
		}
		cout << '\n';
	}

	return 0;
}
