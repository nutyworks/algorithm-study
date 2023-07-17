#include <iostream>
#include <stack>
#include <vector>

#define PUSH true
#define POP false

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	stack<int> ns;
	vector<bool> ops;
	int n, max = 0;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;

		if (a > max) {
			while (max < a) {
				max++;
				ns.push(max);
				ops.push_back(PUSH);
			}
			ns.pop();
			ops.push_back(POP);
		} else {
			if (a == ns.top()) {
				ns.pop();
				ops.push_back(POP);
			} else {
				cout << "NO";
				return 0;
			}
		}
	}

	for (auto op : ops) {
		cout << (op ? '+' : '-') << '\n';
	}

	return 0;
}
