#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int b[500][500], w, h, maxsum = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    // vertical I
    for (int y = 0; y < h - 3; y++) {
        for (int x = 0; x < w; x++) {
            maxsum = max(maxsum, b[y][x] + b[y+1][x] + b[y+2][x] + b[y+3][x]);
        }
    }

    // horizontal I
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w - 3; x++) {
            maxsum = max(maxsum, b[y][x] + b[y][x+1] + b[y][x+2] + b[y][x+3]);
        }
    }

    // O
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w - 1; x++) {
            maxsum = max(maxsum, b[y][x] + b[y][x+1] + b[y+1][x] + b[y+1][x+1]);
        }
    }

    // vertical 3x2
    for (int y = 0; y < h - 2; y++) {
        for (int x = 0; x < w - 1; x++) {
            maxsum = max({
                maxsum, 
                b[y+0][x+0] + b[y+1][x+0] + b[y+2][x+0] + b[y+2][x+1], // L
                b[y+0][x+0] + b[y+0][x+1] + b[y+1][x+1] + b[y+2][x+1], // L rotated
                b[y+0][x+0] + b[y+0][x+1] + b[y+1][x+0] + b[y+2][x+0], // J rotated
                b[y+2][x+0] + b[y+0][x+1] + b[y+1][x+1] + b[y+2][x+1], // J
                b[y+0][x+0] + b[y+1][x+0] + b[y+1][x+1] + b[y+2][x+1], // S rotated
                b[y+0][x+1] + b[y+1][x+0] + b[y+1][x+1] + b[y+2][x+0], // Z rotated
                b[y+0][x+0] + b[y+1][x+0] + b[y+1][x+1] + b[y+2][x+0], // T right
                b[y+0][x+1] + b[y+1][x+1] + b[y+1][x+0] + b[y+2][x+1], // T left
            });
        }
    }

    // horizontal 2x3
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w - 2; x++) {
            maxsum = max({
                maxsum, 
                b[y+0][x+0] + b[y+0][x+1] + b[y+0][x+2] + b[y+1][x+2],
                b[y+0][x+0] + b[y+1][x+0] + b[y+1][x+1] + b[y+1][x+2],
                b[y+0][x+0] + b[y+1][x+0] + b[y+0][x+1] + b[y+0][x+2],
                b[y+0][x+2] + b[y+1][x+0] + b[y+1][x+1] + b[y+1][x+2],
                b[y+0][x+0] + b[y+0][x+1] + b[y+1][x+1] + b[y+1][x+2],
                b[y+1][x+0] + b[y+0][x+1] + b[y+1][x+1] + b[y+0][x+2],
                b[y+0][x+0] + b[y+0][x+1] + b[y+1][x+1] + b[y+0][x+2],
                b[y+1][x+0] + b[y+1][x+1] + b[y+0][x+1] + b[y+1][x+2],
            });
        }
    }

    cout << maxsum;

    return 0;
}