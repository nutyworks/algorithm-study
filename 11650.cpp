#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, len;

    cin >> n;

    len = n;

    long long *pos = (long long *) malloc(n * sizeof(long long));

    while (n--) { 
        long long a, b;
        cin >> a >> b;
        pos[n] = ((a + 100000) << 32) + (b + 100000);
    }

    sort(pos, pos + len);

    for (int i = 0; i < len; i++) {
        cout << ((pos[i] >> 32) - 100000) << ' ' << ((pos[i] & 0xfffffff) - 100000) << '\n';
    }

    return 0;
}