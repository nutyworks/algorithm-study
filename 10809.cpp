#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int first[26];

	for (int i = 0; i < 26; i++) {
		first[i] = -1;
	}

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int d = s[i] - 'a';
		if (first[d] == -1) {
			first[d] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << first[i] << ' ';
	}

	return 0;
}
