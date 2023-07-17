#include <bits/stdc++.h>

using namespace std;

int white_blue(int paper[128][128], int x, int y, int size) {
    int p0 = paper[y][x], success = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (paper[y + i][x + j] != p0) success = 0;
        }
    }

    if (success) return p0 == 0 ? 0x00010000 : 0x00000001;
    else return white_blue(paper, x, y, size / 2) 
                + white_blue(paper, x + size / 2, y, size / 2) 
                + white_blue(paper, x, y + size / 2, size / 2) 
                + white_blue(paper, x + size / 2, y + size / 2, size / 2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int paper[128][128], n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    int wb = white_blue(paper, 0, 0, n);

    cout << (wb >> 16) << '\n' << (wb & 0xffff);

    return 0;
}