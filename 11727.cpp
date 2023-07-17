#include <iostream>

using namespace std;

int T[1001] = { 0, 1, 3, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  for (int i = 3; i <= 1000; i++) {
    T[i] = (2 * T[i-2] + T[i-1]) % 10007;
  }

  int n;
  cin >> n;
  cout << T[n];

	return 0;
}
