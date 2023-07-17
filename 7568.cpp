#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	vector<pair<int, int>> ds;
	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;
		ds.push_back(make_pair(a, b));
	}

	for (auto d1 : ds) {
		int rank = 0;
		for (auto d2 : ds) {
			if (d1.first < d2.first && d1.second < d2.second) {
				rank++;
			}
		}

		cout << rank + 1 << ' ';
	}

	return 0;
}
