#include <bits/stdc++.h>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int original[20][20], board[20][20];
bool merged[20][20];

void move(int direction, int n) {
    switch (direction) {
        case UP: {
            for (int r = 0; r < n; r++) {
                for (int y = 0; y < n - 1; y++) {
                    for (int x = 0; x < n; x++) {
                        if (board[y][x] == board[y + 1][x] && board[y][x] && !merged[y][x] && !merged[y + 1][x]) {
                            board[y][x] *= 2;
                            board[y + 1][x] = 0;
                            merged[y][x] = true;
                        } else if (board[y][x] == 0) {
                            board[y][x] = board[y + 1][x];
                            board[y + 1][x] = 0;
                            merged[y][x] = merged[y + 1][x];
                        }
                    }
                }
            }

            break;
        }
        case RIGHT: {
            for (int r = 0; r < n; r++) {
                for (int y = 0; y < n; y++) {
                    for (int x = n - 1; x > 0; x--) {
                        if (board[y][x] == board[y][x - 1] && board[y][x] && !merged[y][x] && !merged[y][x - 1]) {
                            board[y][x] *= 2;
                            board[y][x - 1] = 0;
                            merged[y][x] = true;
                        } else if (board[y][x] == 0) {
                            board[y][x] = board[y][x - 1];
                            board[y][x - 1] = 0;
                            merged[y][x] = merged[y][x - 1];
                        }
                    }
                }
            }

            break;
        }
        case DOWN: {
            for (int r = 0; r < n; r++) {
                for (int y = n - 1; y > 0; y--) {
                    for (int x = 0; x < n; x++) {
                        if (board[y][x] == board[y - 1][x] && board[y][x] && !merged[y][x] && !merged[y - 1][x]) {
                            board[y][x] *= 2;
                            board[y - 1][x] = 0;
                            merged[y][x] = true;
                        } else if (board[y][x] == 0) {
                            board[y][x] = board[y - 1][x];
                            board[y - 1][x] = 0;
                            merged[y][x] = merged[y - 1][x];
                        }
                    }
                }
            }

            break;
        }
        case LEFT: {
            for (int r = 0; r < n; r++) {
                for (int y = 0; y < n; y++) {
                    for (int x = 0; x < n - 1; x++) {
                        if (board[y][x] == board[y][x + 1] && board[y][x] && !merged[y][x] && !merged[y][x + 1]) {
                            board[y][x] *= 2;
                            board[y][x + 1] = 0;
                            merged[y][x] = true;
                        } else if (board[y][x] == 0) {
                            board[y][x] = board[y][x + 1];
                            board[y][x + 1] = 0;
                            merged[y][x] = merged[y][x + 1];
                        }
                    }
                }
            }

            break;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            merged[y][x] = false;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, max_num = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> original[i][j];
        }
    }

    for (int i1 = 0; i1 < 4; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                for (int i4 = 0; i4 < 4; i4++) {
                    for (int i5 = 0; i5 < 4; i5++) {
                        for (int y = 0; y < n; y++) for (int x = 0; x < n; x++) board[y][x] = original[y][x];
                        move(i1, n);
                        move(i2, n);
                        move(i3, n);
                        move(i4, n);
                        move(i5, n);
                        for (int y = 0; y < n; y++) for (int x = 0; x < n; x++) max_num = max(max_num, board[y][x]);
                    }
                }
            }
        }
    }
    
    cout << max_num;

    return 0;
}