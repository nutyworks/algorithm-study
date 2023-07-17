#include <bits/stdc++.h>

using namespace std;

int ret[1000000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    stack<pair<int, int> > numbers;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (!numbers.empty() && numbers.top().second < num) {
            ret[numbers.top().first] = num;
            numbers.pop();
        }

        numbers.push({i, num});
    }

    for (int i = 0; i < n; i++) {
        if (ret[i]) cout << ret[i] << ' ';
        else cout << "-1 ";
    }

    return 0;
}