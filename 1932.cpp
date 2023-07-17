#include <bits/stdc++.h>

static int tri[500][500];
static int sum[500][500];

using namespace std;

int dp(int x, int y) {
    if (sum[y][x]) return sum[y][x];
    if (x == 0 && y == 0) return tri[0][0];

    return sum[y][x] = tri[y][x] + max(x == y ? 0 : dp(x, y - 1), x == 0 ? 0 : dp(x - 1, y - 1));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int result = dp(i, n - 1);
        if (result > max) max = result;
    }

    cout << max;

    return 0;
}