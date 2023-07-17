#include <iostream>

using namespace std;

int mod1234567891[] = { 1, 31, 961, 29791, 923521, 28629151, 887503681, 352120509, 1039192651, 116207015, 1133281683, 563831225, 194817501, 1101070967, 799866920, 104516700, 770881918, 440549529, 76788598, 1145878647, 954337109, 1189388886, 1068586627, 1027420271, 985831126, 931135522, 470139689 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

  long long hash = 0;
	int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    hash += mod1234567891[i] * (c - 'a' + 1);
    hash %= 1234567891;
  }

  cout << hash;

	return 0;
}
