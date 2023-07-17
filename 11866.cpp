#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, k;
  queue<int> q;

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  cout << '<';
  int i = k;

  while (q.size() > 1) {
    if (--i == 0) {
      int dead = q.front();
      q.pop();
      cout << dead << ", ";
      i = k;
    } else {
      q.push(q.front());
      q.pop();
    }
  }

  cout << q.front() << '>';

	return 0;
}
