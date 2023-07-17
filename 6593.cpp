#include <bits/stdc++.h>

using namespace std;

const int dx[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1) {
        queue<tuple<int, int, int> > q;
        char building[30][30][30];
        int lx, ly, lz, time = 0, end = 0;
        cin >> lz >> ly >> lx;

        if (lz + ly + lz == 0) break;

        for (int z = 0; z < lz; z++) {
            for (int y = 0; y < ly; y++) {
                for (int x = 0; x < lx; x++) {
                    cin >> building[z][y][x];

                    if (building[z][y][x] == 'S') {
                        q.push({x, y, z});
                        building[z][y][x] = '#';
                    }
                }
            }
        }

        while (!q.empty() && !end) {
            int nq = q.size();
            while (nq--) {
                int tx, ty, tz;
                tie(tx, ty, tz) = q.front();
                q.pop();

                for (int i = 0; i < 6; i++) {
                    int nx = tx + dx[i], ny = ty + dy[i], nz = tz + dz[i];

                    if (nx < 0 || ny < 0 || nz < 0 
                        || nx >= lx || ny >= ly || nz >= lz) continue;
                    if (building[nz][ny][nx] == '#') continue;

                    if (building[nz][ny][nx] == 'E') end = 1;
                    q.push({nx, ny, nz});
                    building[nz][ny][nx] = '#';
                }
            }
            time++;
        }

        if (end) cout << "Escaped in " << time << " minute(s).\n";
        else cout << "Trapped!\n";
    }

    return 0;
}