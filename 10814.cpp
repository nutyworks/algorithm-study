#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator() (const pair<int, string> &a, const pair<int, string> &b) const {
		return a.first < b.first;
	}
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<pair<int, string>> accounts;
	int n;
	cin >> n;

	while (n--) {
		int age;
		string name;
		cin >> age >> name;
		accounts.push_back(make_pair(age, name));
	}

	cmp c;

	stable_sort(accounts.begin(), accounts.end(), c);

	for (auto account : accounts) {
		cout << account.first << ' ' << account.second << '\n';
	}

	return 0;
}
