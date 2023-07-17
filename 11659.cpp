#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
  int n, m, i, j, *sum = (int *) malloc((n + 1) * sizeof(int));
  cin >> n >> m;

  *sum = 0;
 
  for (int i = 1; i <= n; i++) {
    cin >> j;
    sum[i] = sum[i-1] + j;
  }

  while (m--) {
    cin >> i >> j;
    cout << sum[j] - sum[i-1] << '\n';
  }

  free(sum);

	return 0;
}
