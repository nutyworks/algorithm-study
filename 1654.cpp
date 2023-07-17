#include <iostream>
#include <cstdlib>

#define safeaverage(a, b) (((a) >> 1) + ((b) >> 1) + ((a) % 2) * ((b) % 2))

using namespace std;

int yeongsik(int *lans, int size, int cm, int nreqlans) {
  long long count = 0;

  for (int i = 0; i < size; i++) {
    count += lans[i] / cm;
  }

  return count >= nreqlans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int yeongsiklan, nreqlans, *lans;
  cin >> yeongsiklan >> nreqlans;

  lans = (int *) malloc(sizeof(int) * yeongsiklan);

  for (int i = 0; i < yeongsiklan; i++) {
    int l;
    cin >> l;
    lans[i] = l;
  }

  long long start = 1, end = 0x7fffffff, maxlen = 0;

  while (start <= end) {
    long long mid = safeaverage(start, end);
    int isvalid = yeongsik(lans, yeongsiklan, mid, nreqlans);

    if (isvalid) {
      maxlen = maxlen > mid ? maxlen : mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << maxlen;

  free(lans);

	return 0;
}
