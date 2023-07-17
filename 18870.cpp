#include <iostream>
#include <algorithm>

using namespace std;

int ibsearch(int* arr, unsigned int start, unsigned int end, int value);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, arr[1000000], set[1000000];

  cin >> n;

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    arr[i] = set[i] = t;
  }

  sort(set, set + n);

  int dn = 0;

  for (int i = 0; i < n; i++) {
    if (set[i] != set[dn]) {
      dn++;
      set[dn] = set[i];
    }
  }

  dn++;

  for (int i = 0; i < n; i++) {
    cout << ibsearch(set, 0, dn - 1, arr[i]) << ' ';
  }

	return 0;
}

int ibsearch(int* arr, unsigned int start, unsigned int end, int value) {
  unsigned int mid = (start + end) / 2;
  if (start == end) {
    return arr[mid] == value ? mid : -1;
  } else {
    if (arr[mid] == value) {
      return mid;
    } else if (arr[mid] > value) {
      return ibsearch(arr, start, mid - 1, value);
    } else {
      return ibsearch(arr, mid + 1, end, value);
    }
  }
}
