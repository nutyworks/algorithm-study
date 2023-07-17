#include <iostream>

using namespace std;

// int waytosum[11];

// int mayisumwith123(int n) {
//   if (n == 1) return 1;
//   if (n == 2) return 2;
//   if (n == 3) return 4;
//   if (n < 1) return 0;
//   if (waytosum[n] > 0) return waytosum[n];
//   return (waytosum[n] = mayisumwith123(n-1) + mayisumwith123(n-2) + mayisumwith123(n-3));
// }

int arr[11] = { 0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

  int n;
  cin >> n;

  while (n--) {
    int a;
    cin >> a;
    cout << arr[a] << '\n';
  }

	return 0;
}
