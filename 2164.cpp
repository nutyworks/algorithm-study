#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	queue<int> cards;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cards.push(i);
	}

	while (cards.size() > 2) {
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}

	cout << cards.back();

	return 0;
}
