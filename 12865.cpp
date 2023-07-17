#include <iostream>
using namespace std;

int stuffs_w[101], stuffs_v[101], d[101][100001];

int knapsack(int n, int w);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, k;
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		int w, v;
		cin >> w >> v;
		stuffs_w[i] = w;
		stuffs_v[i] = v;
	}

	cout << knapsack(n, k);

	return 0;
}

int knapsack(int n, int w) {
	if (d[n][w] > 0) return d[n][w];
	if (n <= 0 || w <= 0) {
		return 0;
	}
	if (stuffs_w[n] > w) {
		return (d[n][w] = knapsack(n - 1, w));
	} else {
		int a = knapsack(n - 1, w);
		int b = stuffs_v[n] + knapsack(n - 1, w - stuffs_w[n]);

		return (d[n][w] = a > b ? a : b);
	}
}