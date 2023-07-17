#include <iostream>

using namespace std;

int one[1000001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    int minval = 0x7fffffff;
    if (i % 2 == 0) {
      minval = one[i / 2] + 1;
    }
    if (i % 3 == 0) {
      minval = min(one[i / 3] + 1, minval);
    }
    one[i] = min(one[i - 1] + 1, minval);
  }

  cout << one[n];

	return 0;
}
