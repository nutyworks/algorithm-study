#include <bits/stdc++.h>

using namespace std;

int photo[1001][1001];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int r, c, q;
    cin >> r >> c >> q;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int t;
            cin >> t;
            photo[i][j] = t + photo[i][j - 1] + photo[i - 1][j] - photo[i - 1][j - 1];
        }
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << (photo[r2][c2] - photo[r1 - 1][c2] - photo[r2][c1 - 1] + photo[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
    }

    return 0;
}