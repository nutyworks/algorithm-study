#include <iostream>
#include <set>

using namespace std;

struct cmp {
	bool operator() (const string &a, const string &b) const {
		if (a.length() == b.length()) {
			return a < b;
		} else {
			return a.length() < b.length();
		}
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	set<string, cmp> dict;
	int n;
	cin >> n;

	while (n--) {
		string word;
		cin >> word;
		dict.insert(word);
	}

	for (auto word : dict) {
		cout << word << '\n';
	}

	return 0;
}
