#include <bits/stdc++.h>

using namespace std;

char paper[2187][2187];

int a = 0, b = 0, c = 0;

void cut_paper(int size, int x, int y) {
    char p0 = paper[y][x];
    bool success = true;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (paper[y + i][x + j] != p0) success = false;
        }
    }

    if (success) {
        if (p0 == -1) a++;
        else if (p0 == 0) b++;
        else c++;

        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cut_paper(size / 3, x + j * size / 3, y + i * size / 3);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            paper[i][j] = t;
        }
    }

    cut_paper(n, 0, 0);

    cout << a << '\n' << b << '\n' << c;

    return 0;
}