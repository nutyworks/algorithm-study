#include <bits/stdc++.h>

using namespace std;

const int hdx[8] = {-2, -1, -1, -2, 2, 1, 1, 2};
const int hdy[8] = {1, 2, -2, -1, -1, -2, 2, 1};
const int mdx[4] = {-1, 1, 0, 0};
const int mdy[4] = {0, 0, -1, 1};

unsigned int board[200][200];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<tuple<char, int, int> > q;
    int k, w, h, moves = 0;
    bool end = 0;
    cin >> k >> w >> h;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> board[y][x];
        }
    }

    q.push({0, 0, 0});
    board[0][0] = 0xfffffffe;

    while (!q.empty()) {
        int nq = q.size();
        while (nq--) {
            int tx, ty;
            char hmove;
            tie(hmove, tx, ty) = q.front();
            q.pop();

            if (tx == w - 1 && ty == h - 1) {
                end = 1;
                goto finish;
            }

            // making monkey move
            for (int i = 0; i < 4; i++) {
                int nx = tx + mdx[i], ny = ty + mdy[i];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if (board[ny][nx] == 1) continue;
                if (board[ny][nx] & (2 << hmove)) continue;

                q.push({hmove, nx, ny});
                board[ny][nx] = 0xfffffffe << hmove;
            }

            if (hmove >= k) continue;

            for (int i = 0; i < 8; i++) {
                int nx = tx + hdx[i], ny = ty + hdy[i];

                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if (board[ny][nx] == 1) continue;
                if (board[ny][nx] & (4 << hmove)) continue;

                q.push({hmove + 1, nx, ny});
                board[ny][nx] = 0xfffffffe << (hmove + 1);
            }
        }
        moves++;
    }

finish:
    cout << (end ? moves : -1);

    return 0;
}