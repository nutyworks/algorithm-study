#include <bits/stdc++.h>

using namespace std;

char b[3072][6144];

void make_star(int n, int x, int y) {
    if (n == 3) {
        b[y][x] = '*';
        b[y+1][x-1] = '*';
        b[y+1][x+1] = '*';
        b[y+2][x-2] = '*';
        b[y+2][x-1] = '*';
        b[y+2][x+0] = '*';
        b[y+2][x+1] = '*';
        b[y+2][x+2] = '*';
        return;
    }
    make_star(n / 2, x, y);
    make_star(n / 2, x - n / 2, y + n / 2);
    make_star(n / 2, x + n / 2, y + n / 2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 3072; i++) fill(b[i], b[i] + 6144, ' ');

    int n;
    cin >> n;

    make_star(n, n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n * 2; j++) {
            cout << b[i][j];
        }
        cout << " \n";
    }

    return 0;
}