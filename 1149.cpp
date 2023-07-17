#include <bits/stdc++.h>

using namespace std;

#define R 0
#define G 1
#define B 2

int rgb[1000][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rgb[i][R] >> rgb[i][G] >> rgb[i][B];
    }

    for (int i = 1; i < n; i++) {
        rgb[i][R] += min(rgb[i-1][G], rgb[i-1][B]);
        rgb[i][G] += min(rgb[i-1][R], rgb[i-1][B]);
        rgb[i][B] += min(rgb[i-1][R], rgb[i-1][G]);
    }

    cout << min({rgb[n-1][R], rgb[n-1][G], rgb[n-1][B]});

    return 0;
}