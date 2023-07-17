#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int from, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }

    int other = 6 - from - to;

    hanoi(n - 1, from, other);
    hanoi(1, from, to);
    hanoi(n - 1, other, to);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 3);

    return 0;
}