#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<pair<int, int>> coords;
	int n;
	cin >> n;

	while (n--) {
		int x, y;
		cin >> x >> y;
		coords.push_back(make_pair(y, x));
	}

	sort(coords.begin(), coords.end());

	for (auto coord : coords) {
		cout << coord.second << ' ' << coord.first << '\n';
	}

	return 0;
}
