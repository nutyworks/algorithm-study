#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> ratings;
  int n;
  cin >> n;

  if (n == 0) {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ratings.push_back(t);
  }

  sort(ratings.begin(), ratings.end());

  int nexclude = (int)(0.15 * n + 0.5);

  int sum = 0;
  
  for (int i = nexclude; i < n - nexclude; i++) {
    sum += ratings[i];
  }

  cout << (int)((double) sum / (n - nexclude * 2) + 0.5);

  return 0;
}
