#include <iostream>

using namespace std;

int fib[1001] = { 1, 1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  for (int i = 2; i < 1001; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % 10007;
  }

  int n;
  cin >> n;
  cout << fib[n];

	return 0;
}
