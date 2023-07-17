#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<string> itop;
    map<string, int> ptoi;
    int n, m;
    cin >> n >> m;

    itop.push_back("");

    for (int i = 1; i <= n; i++) {
        string p;
        cin >> p;

        itop.push_back(p);
        ptoi.insert_or_assign(p, i);
    }

    while (m--) {
        string query;
        cin >> query;

        char first = query.at(0);
        if (first >= '0' && first <= '9') {
            int iquery = stoi(query);
            cout << itop[iquery] << '\n';
        } else {
            cout << ptoi[query] << '\n';
        }
    }

    return 0;
}