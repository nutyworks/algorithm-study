#include <iostream>
#include <tuple>

using namespace std;

pair<int, int> factor_two_five(int n) {
  int two = 0, five = 0;
  while (n > 0) {
    if (n % 2 == 0) {
      n /= 2;
      ++two;
    } else if (n % 5 == 0) {
      n /= 5;
      ++five;
    } else {
      break;
    }
  }

  return make_pair(two, five);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, twos = 0, fives = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int t1, t2;
    tie(t1, t2) = factor_two_five(i);

    twos += t1;
    fives += t2;
  }

  cout << (twos < fives ? twos : fives);

	return 0;
}
