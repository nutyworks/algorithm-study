#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

#define VISITED 0x70000000

void bfs(int ocean[300][300], int visited[300][300], int w, int h, int x, int y) {
    queue<pair<int, int> > q;
    
    q.push({x, y});
    visited[y][x] = 1;

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (ocean[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            q.push({nx, ny});
            visited[ny][nx] = 1;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, h, ocean[300][300], mv[300][300], parts = 0, time = 0;
    cin >> h >> w;

    for (int y = 0; y < h; y++) {
        fill(mv[y], mv[y] + w, 1);
        mv[y][0] = mv[y][w - 1] = 1;
        for (int x = 0; x < w; x++) {
            cin >> ocean[y][x];
        }
    }

    do {
        parts = 0;
        time++;

        for (int y = 1; y < h - 1; y++) {
            fill(mv[y] + 1, mv[y] + w - 1, 0);
            for (int x = 1; x < w - 1; x++) {
                for (int i = 0; i < 4; i++) {
                    if (ocean[y][x]) mv[y][x] += !ocean[y + dy[i]][x + dx[i]];
                }
            }
        }
        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                ocean[y][x] -= mv[y][x];
                if (ocean[y][x] < 0) ocean[y][x] = 0;
            }
        }

        for (int y = 1; y < h - 1; y++) {
            fill(mv[y], mv[y] + w, 0);
        }

        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {
                if (!mv[y][x] && ocean[y][x] > 0) {
                    bfs(ocean, mv, w, h, x, y);
                    parts++;
                }
            }
        }
    } while (parts == 1);

    cout << (parts ? time : 0);

    return 0;
}