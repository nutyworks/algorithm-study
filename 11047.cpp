#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, money, kinda[10] = {}, c = 0;
  cin >> n >> money;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    kinda[i] = a;
  }

  while (n--) {
    int k = kinda[n];
    c += money / k;
    money %= k;
  }

  cout << c;

	return 0;
}
