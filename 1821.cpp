#include <iostream>

using namespace std;

int ctable[10][10];
int nCr(int n, int r) {
	if (n == r || r == 0) return 1;
	else if (ctable[n][r] > 0) return ctable[n][r];
	else return ctable[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int checksum(int lines, int *arr, int expected) {
  int sum = 0;
  for (int i = 0; i < lines; i++) {
    sum += arr[i] * nCr(lines - 1, i);
  }
  return sum == expected;
}

int permute_next(int *current, unsigned int length) {
  int i = length - 1;

  while (i >= 0 && current[i - 1] >= current[i]) {
    i--;
  }

  if (i < 0) { // no next permutation exists
    return 0;
  }

  int j = length;

  while (j > i && current[j - 1] <= current[i - 1]) {
    j--;
  }

  std::swap(current[j - 1], current[i - 1]);
  i++;
  j = length;

  while (i < j) {
    std::swap(current[j - 1], current[i - 1]);
    i++;
    j--;
  }
  return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, f;
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  cin >> n >> f;

  // if (n == 1) {
  //   cout << 1;
  //   return 0;
  // }

  do {
    if (checksum(n, arr, f)) {
      break;
    }
  } while (permute_next(arr, n));

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

	return 0;
}
