#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;

	cin >> n;
	while (n--) {
		int score = 0, sum = 0;
		string s;
		cin >> s;

		for (char c : s) {
			if (c == 'O') {
				score++;
				sum += score;
			} else {
				score = 0;
			}
		}

		cout << sum << '\n';
	}

	return 0;
}
