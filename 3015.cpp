#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> heights;
    int n;
    long long cnt = 0;

    cin >> n;

    while (n--) {
        int h;
        cin >> h;

        auto bigger = upper_bound(heights.rbegin(), heights.rend(), h);
        int hidden = distance(bigger, heights.rend()) - 1;

        cnt += heights.size();
        if (hidden > 0) cnt -= hidden;

        while (!heights.empty() && heights.back() < h) {
            int ph = heights.back();
            heights.pop_back();
        }

        heights.push_back(h);
    }

    cout << cnt;

    return 0;
}