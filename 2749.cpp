#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  long long n;
  int a = 0, b = 1, t;
  cin >> n;

  int target = n % 1500000;

  for (int i = 0; i < target; i++) {
    t = (a + b) % 1000000;
    a = b;
    b = t;
  }

  cout << a;

	return 0;
}
