#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<pair<int, int> > height;
    int n;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;

        while (!height.empty() && height.back().second <= h) {
            height.pop_back();
        }

        if (height.empty()) cout << "0 ";
        else cout << height.back().first << ' ';

        height.push_back(make_pair(i, h));
    }

    return 0;
}