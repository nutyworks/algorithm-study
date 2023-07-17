#include <bits/stdc++.h>

using namespace std;

bool notebook[40][40];
int sticker[10][10];

int get_sticker(int w, int h) {
    int size = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> sticker[i][j];
            if (sticker[i][j]) size++;
        }
    }

    return size;
}

tuple<bool, int, int> get_stickable_pos_with_direction(int d, int nw, int nh, int sw, int sh) {
    for (int y = 0; y < nh - sh + 1; y++) {
        for (int x = 0; x < nw - sw + 1; x++) {
            bool stickable = true;
            for (int dy = 0; dy < sh; dy++) {
                for (int dx = 0; dx < sw; dx++) {
                    if (sticker[dy][dx] && notebook[y + dy][x + dx]) {
                        stickable = false;
                    }
                }
            }
            if (stickable) return { true, x, y };
        }
    }

    return { false, -1, -1 };
}

void stick_at(int x, int y, int sw, int sh) {
    for (int dy = 0; dy < sh; dy++) {
        for (int dx = 0; dx < sw; dx++) {
            notebook[y + dy][x + dx] |= sticker[dy][dx];
        }
    }
}

void rotate_sticker(int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            sticker[x][height - 1 - y] += (sticker[y][x] & 1) ? 2 : 0;
        }
    }

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            sticker[y][x] >>= 1;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w, k, cnt = 0;

    cin >> h >> w >> k;

    while (k--) {
        int width, height, t;
        cin >> height >> width;

        int size = get_sticker(width, height);

        for (int d = 0; d < 4; d++) {
            bool s;
            int x, y;
            tie(s, x, y) = get_stickable_pos_with_direction(d, w, h, width, height);
            if (s) {
                stick_at(x, y, width, height);
                cnt += size;
                break;
            }
            rotate_sticker(width, height);
            t = width, width = height, height = t;
        }
    }

    cout << cnt;

    return 0;
}