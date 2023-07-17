#include <iostream>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

  map<string, string> accounts;
	int n, m;
  cin >> n >> m;
  string id, name;

  while (n--) {
    cin >> id >> name;
    accounts.insert(make_pair(id, name));
  }

  while (m--) {
    cin >> id;
    auto acc = accounts.find(id);

    cout << acc->second << '\n';
  }

	return 0;
}
