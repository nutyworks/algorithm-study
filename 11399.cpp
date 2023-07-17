#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  vector<int> time;
  int n, a;
  long long sum = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a;
    time.push_back(a);
  }

  sort(time.begin(), time.end());

  for (int i = 0; i < n; i++) {
    sum += time[i] * (n - i);
  }

  cout << sum;

	return 0;
}
