#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, t;

    cin >> a >> b;

    if (a == b) {
        cout << "0\n";
        return 0;
    }

    if (a > b) {
        t = a;
        a = b;
        b = t;
    }

    cout << b - a - 1 << '\n';

    for (a++; a < b; a++) {
        cout << a << ' ';
    }

    return 0;
}