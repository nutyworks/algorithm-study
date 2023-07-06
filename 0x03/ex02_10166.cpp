#include <bits/stdc++.h>

using namespace std;

int blocked[2001][2001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int d1, d2, cnt = 0;
    cin >> d1 >> d2;

    for (int r = d1; r <= d2; r++) {
        for (int th = 1; th <= r; th++) {
            int g = gcd(r, th);

            if (!blocked[th / g][r / g]) {
                blocked[th / g][r / g] = 1;
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}