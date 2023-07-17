#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int fib[41] = { 0, 1 };

  for (int i = 2; i < 41; i++) {
    fib[i] = fib[i - 2] + fib[i - 1];
  }

  int n, a;
  cin >> n;
  while (n--) {
    cin >> a;
    if (a == 0) {
      cout << "1 0\n";
    } else {
      cout << fib[a - 1] << ' ' << fib[a] << '\n';
    }
  }

	return 0;
}
