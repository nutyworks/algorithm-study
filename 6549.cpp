#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<tuple<int, int, int> > heights;

    while (1) {
        int n;
        long long max = 0;
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i <= n; i++) {
            int h;

            if (n == i) h = 0;
            else cin >> h;

            int from = i, to = i, height = h;

            while (!heights.empty() && get<2>(heights.back()) > h) {
                int tf, tt, th, nf, nt, nh;
                tie(tf, tt, th) = heights.back();
                heights.pop_back();

                #ifdef DEBUG
                for (auto e : heights) cout << '(' << get<0>(e) << ',' << get<1>(e) << ',' << get<2>(e) << ") ";
                cout << '\n';
                #endif

                long long area = (tt - tf + 1) * (long long) th;
                if (max < area) max = area;

                if (heights.empty() || get<2>(heights.back()) <= h) {
                    heights.push_back({tf, tt, th});

                    #ifdef DEBUG
                    for (auto e : heights) cout << '(' << get<0>(e) << ',' << get<1>(e) << ',' << get<2>(e) << ") ";
                    cout << '\n';
                    #endif

                    break;
                }

                tie(nf, nt, nh) = heights.back();
                heights.pop_back();

                #ifdef DEBUG
                for (auto e : heights) cout << '(' << get<0>(e) << ',' << get<1>(e) << ',' << get<2>(e) << ") ";
                cout << '\n';
                #endif

                heights.push_back({nf, tt, th < nh ? th : nh});

                #ifdef DEBUG
                for (auto e : heights) cout << '(' << get<0>(e) << ',' << get<1>(e) << ',' << get<2>(e) << ") ";
                cout << '\n';
                #endif
            }

            heights.push_back({from, to, height});

            #ifdef DEBUG
            for (auto e : heights) cout << '(' << get<0>(e) << ',' << get<1>(e) << ',' << get<2>(e) << ") ";
            cout << '\n';
            #endif
        }

        while (!heights.empty()) heights.pop_back();

        cout << max << '\n';
    }

    return 0;
}