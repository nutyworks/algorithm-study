#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	while (n--) {
		string s;
		int count = 0;
		bool no = false;

		cin >> s;
		for (auto c : s) {
			if (c == '(') { count++; }
			if (count < 0) { no = true; }
			if (c == ')') { count--; }
			if (count < 0) { no = true; }
		}

		if (count != 0) { no = true; }

		cout << (no ? "NO" : "YES") << '\n';
	}

	return 0;
}
