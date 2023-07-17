#include <bits/stdc++.h>

using namespace std;

char room[10][10];
vector<tuple<int, int, int>> cctv;
vector<tuple<int, int, int, int>> selected;

const int cctv_directions[6] = {0, 4, 2, 4, 4, 1};

int min_area = 64;

void left(int x, int y) {
    while (true) {
        if (room[y][x] == 6) break;
        room[y][x] = 7;
        x--;
    }
}

void right(int x, int y) {
    while (true) {
        if (room[y][x] == 6) break;
        room[y][x] = 7;
        x++;
    }
}

void up(int x, int y) {
    while (true) {
        if (room[y][x] == 6) break;
        room[y][x] = 7;
        y--;
    }
}

void down(int x, int y) {
    while (true) {
        if (room[y][x] == 6) break;
        room[y][x] = 7;
        y++;
    }
}

int calculate_area(int w, int h) {
    for (auto c : selected) {
        int type, x, y, dir;
        tie(type, x, y, dir) = c;

        if (type == 1) {
            if (dir == 0) right(x, y);
            else if (dir == 1) down(x, y);
            else if (dir == 2) left(x, y);
            else up(x, y);
        } else if (type == 2) {
            if (dir == 0) { left(x, y); right(x, y); }
            else { up(x, y); down(x, y); }
        } else if (type == 3) {
            if (dir == 0) { up(x, y); right(x, y); }
            else if (dir == 1) { right(x, y); down(x, y); }
            else if (dir == 2) { down(x, y); left(x, y); }
            else { left(x, y); up(x, y); }
        } else if (type == 4) {
            if (dir == 0) { left(x, y); up(x, y); right(x, y); }
            else if (dir == 1) { up(x, y); right(x, y); down(x, y); }
            else if (dir == 2) { right(x, y); down(x, y); left(x, y); }
            else { down(x, y); left(x, y); up(x, y); }
        } else {
            left(x, y); up(x, y); right(x, y); down(x, y);
        }
    }

    int area = 0;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (room[i][j] == 0) area++;
            else if (room[i][j] == 7) room[i][j] = 0;
        }
    }

    return area;
}

void set_cctv(int n, int i, int w, int h) {
    if (n == i) {
        int area = calculate_area(w, h);
        min_area = min(area, min_area);
        return;
    }

    int type, x, y;
    tie(type, x, y) = cctv[i];

    for (int d = 0; d < cctv_directions[type]; d++) {
        selected.emplace_back(type, x, y, d);
        set_cctv(n, i + 1, w, h);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;

    fill(room[0], room[0] + w + 2, 6);
    for (int i = 1; i <= h; i++) {
        room[i][0] = room[i][w + 1] = 6;
        for (int j = 1; j <= w; j++) {
            int a;
            cin >> a;
            room[i][j] = a;

            if (a >= 1 && a <= 5) {
                cctv.emplace_back(a, j, i);
            }
        }
    }
    fill(room[h + 1], room[h + 1] + w + 2, 6);

    set_cctv(cctv.size(), 0, w, h);

    cout << min_area;

    return 0;
}