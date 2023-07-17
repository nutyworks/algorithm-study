#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  vector<string> jobs, realjobs;
  int m, n;
  string name;
  cin >> m >> n;

  while (m--) {
    cin >> name;
    jobs.push_back(name);
  }

  sort(jobs.begin(), jobs.end());

  while (n--) {
    cin >> name;
    if (binary_search(jobs.begin(), jobs.end(), name)) {
      realjobs.push_back(name);
    }
  }

  sort(realjobs.begin(), realjobs.end());

  cout << realjobs.size() << '\n';

  for (auto s : realjobs) {
    cout << s << '\n';
  }

	return 0;
}
