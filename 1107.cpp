#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
    int cnt = 0;
    do cnt++; while (n /= 10);
    return cnt;
}

bool is_valid_channel(int channel, vector<int> brokens) {
    do {
        for (int b : brokens) {
            if (channel % 10 == b) return false;
        }
    } while (channel /= 10);

    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int targetch, nbroken, lessch, greaterch;
    vector<int> brokens;

    cin >> targetch >> nbroken;

    while (nbroken--) {
        int t;
        cin >> t;
        brokens.push_back(t);
    }

    if (brokens.size() == 10) {
        lessch = -1000000, greaterch = 1000000;
    } else {
        for (lessch = targetch; lessch >= 0; lessch--) {
            if (is_valid_channel(lessch, brokens)) break;
        }

        for (greaterch = targetch; greaterch < 999900; greaterch++) {
            if (is_valid_channel(greaterch, brokens)) break;
        }
    }

    if (lessch == -1) lessch = -1000000;

    cout << min({abs(targetch - 100), digits(lessch) + targetch - lessch, digits(greaterch) + greaterch - targetch});

    return 0;
}