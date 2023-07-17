#include <bits/stdc++.h>

using namespace std;

#define CW 1
#define CCW -1

bool gear[4][8];

bool should_rotate(int g1, int g2) {
    if (g1 > g2) {
        int t = g1;
        g1 = g2;
        g2 = t;
    }

    return gear[g1][2] != gear[g2][6];
}

void rotate_gear(int igear, int rotation, int direction) {
    bool t;
    bool *g = gear[igear];

    if (direction) {
        int ng = igear + direction;
        if (ng >= 0 && ng <= 3 && should_rotate(igear, ng)) {
            rotate_gear(ng, -rotation, direction);
        }
    } else {
        int ng1 = igear - 1, ng2 = igear + 1;
        if (ng1 >= 0 && ng1 <= 3 && should_rotate(igear, ng1)) {
            rotate_gear(ng1, -rotation, -1);
        }
        if (ng2 >= 0 && ng2 <= 3 && should_rotate(igear, ng2)) {
            rotate_gear(ng2, -rotation, 1);
        }
    }

    if (rotation == CW) {
        t = g[0], g[0] = g[7], g[7] = g[6], g[6] = g[5], g[5] = g[4];
        g[4] = g[3], g[3] = g[2], g[2] = g[1], g[1] = t;
    } else if (rotation == CCW) {
        t = g[0], g[0] = g[1], g[1] = g[2], g[2] = g[3], g[3] = g[4];
        g[4] = g[5], g[5] = g[6], g[6] = g[7], g[7] = t;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    for (int g = 0; g < 4; g++) {
        for (int i = 0; i < 8; i++) {
            char c;
            cin >> c;
            gear[g][i] = c - '0';
        }
    }

    int rotates;
    cin >> rotates;

    while (rotates--) {
        int igear, rotation;
        cin >> igear >> rotation;

        rotate_gear(igear - 1, rotation, 0);
    }

    int score = gear[0][0] + (gear[1][0] << 1) + (gear[2][0] << 2) + (gear[3][0] << 3);
    cout << score;

    return 0;
}