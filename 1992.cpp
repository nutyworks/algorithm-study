#include <bits/stdc++.h>

using namespace std;

char video[64][64];

void quad(int length, int x, int y) {
    int p0 = video[y][x];
    bool success = true;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (video[y + i][x + j] != p0) success = false;
        }
    }

    if (success) {
        cout << p0;
        return;
    }

    cout << '(';
    quad(length / 2, x, y);
    quad(length / 2, x + length / 2, y);
    quad(length / 2, x, y + length / 2);
    quad(length / 2, x + length / 2, y + length / 2);
    cout << ')';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> video[i][j];
            video[i][j] -= '0';
        }
    }

    quad(n, 0, 0);

    return 0;
}