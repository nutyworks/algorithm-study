#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

  int count[8001] = {}, sum = 0, n, maxoccur = 0, freq = -4001, center = -4001, j = 0, minval = 4001, maxval = -4001, avg;
  cin >> n;
	
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ++count[4000 + a];
    sum += a;
    minval = min(minval, a);
    maxval = max(maxval, a);
  }

  for (int i = -4000; i <= 4000; i++) {
    int occur = count[4000 + i];
    j += occur;

    if (center == -4001 && j >= (n >> 1) + 1) {
      center = i;
    }

    maxoccur = max(maxoccur, occur);
  }

  for (int i = -4000; i <= 4000; i++) {
    if (count[4000 + i] == maxoccur) {
      if (freq >= -4000) {
        freq = i;
        break;
      } else {
        freq = i;
      }
    }
  }

  if (sum >= 0) {
    avg = sum / (double) n + 0.5;
  } else {
    avg = sum / (double) n - 0.5;
  }

  cout << avg << '\n' << center << '\n' << freq << '\n' << maxval - minval;

	return 0;
}
