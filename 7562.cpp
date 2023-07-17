#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<pair<int, int> > q;
    int n;
    int board[300][300];

    cin >> n;

    while (n--) {
        int size, xi, yi, xf, yf;
        cin >> size >> xi >> yi >> xf >> yf;

        for (int i = 0; i < 300; i++) {
            for (int j = 0; j < 300; j++) {
                board[i][j] = -1;
            }
        }

        q.push({xi, yi});
        board[yi][xi] = 0;
        
        while (!q.empty()) {
            int tx, ty;
            tie(tx, ty) = q.front();
            q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = tx + dx[dir], ny = ty + dy[dir];

                if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                if (board[ny][nx] >= 0) continue;

                q.push({nx, ny});
                board[ny][nx] = board[ty][tx] + 1;
            }
        }
        cout << board[yf][xf] << '\n';
    }

    return 0;
}