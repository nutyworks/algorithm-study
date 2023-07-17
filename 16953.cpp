#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    int a, b, end = 0, time = 0;
    cin >> a >> b;

    q.push(b);

    while (!q.empty()) {
        int nq = q.size();
        while (nq--) {
            int n = q.front();
            q.pop();

            if (n == a) {
                end = 1;
                goto finish;
            }

            if ((n - 1) % 10 == 0 && n >= 11) {
                q.push((n - 1) / 10);
            }
            if (n % 2 == 0 && n >= 2) {
                q.push(n >> 1);
            }
        }

        time++;
    }

finish:
    cout << (end ? time + 1 : -1);

    return 0;
}