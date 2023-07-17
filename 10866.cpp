#include <iostream>
#include <deque>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	deque<int> ns;
	int n;
	cin >> n;

	while (n--) {
		string op;
		cin >> op;
		if (op == "push_front") {
			int i;
			cin >> i;
			ns.push_front(i);
		} else if (op == "push_back") {
			int i;
			cin >> i;
			ns.push_back(i);
		} else if (op == "pop_front") {
			if (ns.size() > 0) {
				cout << ns.front() << '\n';
				ns.pop_front();
			} else {
				cout << "-1\n";
			}
		} else if (op == "pop_back") {
			if (ns.size() > 0) {
				cout << ns.back() << '\n';
				ns.pop_back();
			} else {
				cout << "-1\n";
			}
		} else if (op == "size") {
			cout << ns.size() << '\n';
		} else if (op == "empty") {
			cout << (ns.empty() ? 1 : 0) << '\n';
		} else if (op == "front") {
			if (ns.size() > 0) {
				cout << ns.front() << '\n';
			} else {
				cout << "-1\n";
			}
		} else if (op == "back") {
			if (ns.size() > 0) {
				cout << ns.back() << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}
