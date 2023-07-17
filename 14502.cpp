#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char board[8][8];
int minvirus = 64;

int bfs(int w, int h) {
    queue<pair<int, int>> q;
    int virus = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (board[y][x] == 2) q.push({x, y});
        }
    }

    while (!q.empty()) {
        int tx, ty;
        tie(tx, ty) = q.front();
        q.pop();
        virus++;

        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (board[ny][nx] != 0) continue;

            board[ny][nx] = 4;
            q.push({nx, ny});
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (board[y][x] == 4) board[y][x] = 0;
        }
    }

    return virus;
}

void build_wall_bfs(int w, int h, int depth, int i) {
    if (depth == 3) {
        int v = bfs(w, h);
        minvirus = min(v, minvirus);
        return;
    }

    for (; i < w * h; i++) {
        int y = i / w;
        int x = i % w;

        if (board[y][x]) continue;

        board[y][x] = 3;
        build_wall_bfs(w, h, depth + 1, i);
        board[y][x] = 0;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, h, safearea = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            board[i][j] -= '0';
            if (board[i][j] != 1) safearea++;
        }
    }

    build_wall_bfs(w, h, 0, 0);

    cout << safearea - 3 - minvirus;

    return 0;
}