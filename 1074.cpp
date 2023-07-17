#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {0, 1, 0, 1};
const int dy[4] = {0, 0, 1, 1};

int find_z(int n, int depth, int r, int c, int x, int y) {
    int size = 1 << (n - depth);

    if (r == y && c == x) return 1;

    if (c < x || r < y || c >= x + size || r >= y + size) return -1;

    for (int i = 0; i < 4; i++) {
        int result = find_z(n, depth + 1, r, c, x + size / 2 * dx[i], y + size / 2 * dy[i]);

        if (result != -1) return size * size / 4 * i + result;
    }

    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, r, c;
    cin >> n >> r >> c;

    cout << find_z(n, 0, r, c, 0, 0) - 1;

    return 0;
}