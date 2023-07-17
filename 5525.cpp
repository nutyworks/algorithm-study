#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, d, count = 0;
  string s;
  char before = 0;
  cin >> n >> d >> s;

  d = -1;

  for (char c : s) {
    if (c == 'I') {
      if (before == 'O' && d >= 0) {
        d++;
      } else {
        d = 0;
      }
      if (d >= n) ++count;
    }
    if (c == 'O' && before == 'O') {
      d = -1;
    }

    before = c;
  }

  cout << count;

	return 0;
}
