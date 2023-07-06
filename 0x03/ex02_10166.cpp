#include <bits/stdc++.h>

using namespace std;

int main() {
    int d1, d2, cnt = 0;
    scanf("%d%d", &d1, &d2);

    for (int r = d1; r <= d2; r++) {
        for (int th = 1; th <= r; th++) {
            int g = gcd(r, th);
            int blocked = 0;

            for (int i = 1; i < g; i++) {
                if (r * i >= d1 * g) blocked = 1;
            }

            if (!blocked) cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}