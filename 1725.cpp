#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<tuple<int, int, int> > heights;

    int n;
    long long max = 0;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        int h;

        if (n == i) h = 0;
        else cin >> h;

        int from = i, to = i, height = h;

        while (!heights.empty() && get<2>(heights.back()) > h) {
            int tf, tt, th, nf, nt, nh;
            tie(tf, tt, th) = heights.back();
            heights.pop_back();

            long long area = (tt - tf + 1) * (long long) th;
            if (max < area) max = area;

            if (heights.empty() || get<2>(heights.back()) <= h) {
                heights.push_back({tf, tt, th});

                break;
            }

            tie(nf, nt, nh) = heights.back();
            heights.pop_back();

            heights.push_back({nf, tt, th < nh ? th : nh});
        }

        heights.push_back({from, to, height});
    }

    while (!heights.empty()) heights.pop_back();

    cout << max << '\n';

    return 0;
}