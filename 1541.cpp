#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

  int n, sum = 0, multiplier = 1;
  char c;
	
  while (cin >> n) {
    sum += multiplier * n;
    if (cin >> c) {
      if (c == '-') {
        multiplier = -1;
      }
    } else {
      break;
    }
  }

  cout << sum;

	return 0;
}
