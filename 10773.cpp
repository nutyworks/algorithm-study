#include <iostream>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	stack<int> ns;
	int n;
	cin >> n;

	while (n--) {
		int number;
		cin >> number;
		if (number) {
			ns.push(number);
		} else {
			ns.pop();
		}
	}

	int sum = 0;

	while (!ns.empty()) {
		sum += ns.top();
		ns.pop();
	}

	cout << sum;

	return 0;
}
