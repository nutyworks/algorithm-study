#include <bits/stdc++.h>

using namespace std;

struct serial_cmp {
    bool operator()(const string& a, const string& b) const {
        if (a.size() != b.size()) return a.size() < b.size();
        int asum = 0, bsum = 0;

        for (char ca : a) {
            if (ca >= '0' && ca <= '9') asum += ca - '0';
        }
        for (char cb : b) {
            if (cb >= '0' && cb <= '9') bsum += cb - '0';
        }

        if (asum != bsum) return asum < bsum;

        return a.compare(b) < 0;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<string> serials;
    serial_cmp c;
    int n;

    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        serials.push_back(s);
    }

    sort(serials.begin(), serials.end(), c);

    for (string s : serials) {
        cout << s << '\n';
    }

    return 0;
}