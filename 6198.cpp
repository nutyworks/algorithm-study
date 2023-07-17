#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    stack<int> heights;
    int n;
    long long cnt = 0;

    cin >> n;
    while (n--) {
        int h;
        cin >> h;

        while (!heights.empty() && heights.top() <= h) heights.pop();

        heights.push(h);

        cnt += heights.size() - 1;
    }

    cout << cnt;

    return 0;
}