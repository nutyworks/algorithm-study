#include <iostream>

using namespace std;

long long p[101] = { 0, 1, 1, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  for (int i = 3; i <= 100; i++) {
    p[i] = p[i-3] + p[i-2];
  }

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << p[n] << '\n';
  }

	return 0;
}
