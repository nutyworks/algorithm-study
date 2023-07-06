#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    short a, b;

    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}