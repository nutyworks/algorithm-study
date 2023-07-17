#include <bits/stdc++.h>

#define PASSED_BREAK 4
#define PASSED 2
#define WALL 1
#define NOT_PASSED 0

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w, time = 0;
    char board[1000][1000];
    bool end = 0;
    queue<tuple<bool, int, int> > q;

    cin >> h >> w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y][x];
            board[y][x] -= '0';
        }
    }

    q.push({false, 0, 0});
    board[0][0] = 2;

    while (!q.empty()) {
        int nq = q.size();

        while (nq--) {
            int tx, ty;
            bool broke;
            tie(broke, tx, ty) = q.front();
            q.pop();

            if (tx == w - 1 && ty == h - 1) {
                time++;
                end = true;
                goto finish;
            }

            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

                int status = board[ny][nx];

                if (status & PASSED) continue;
                if (broke && status != NOT_PASSED) continue;
                if (!broke && status == (WALL | PASSED)) continue;

                q.push({(board[ny][nx] & WALL) || broke, nx, ny});
                board[ny][nx] |= broke ? PASSED_BREAK : PASSED;
            }
        }

        time++;
    }

finish: 
    if (end) cout << time;
    else cout << -1;

    return 0;
}