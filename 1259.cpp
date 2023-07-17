#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  string n;
  
  while (true) {
    cin >> n;
    if (n == "0") { break; }

    int ispal = 1;
    auto liter = n.begin();
    auto riter = n.rbegin();

    for (; liter != n.end(); ++liter, ++riter) {
      if (*liter != *riter) { ispal = 0; }
    }

    cout << (ispal ? "yes" : "no") << '\n';
  }

	return 0;
}
