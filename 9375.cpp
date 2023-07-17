#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cnt[30] = {};
    map<string, int> type_to_index;

    int tc;
    cin >> tc;

    while (tc--) {
        for (int i = 0; i < 30; i++) cnt[i] = 0;
        type_to_index.clear();

        int wears, types = 0, combinations = 1;
        cin >> wears;

        while (wears--) {
            string name, type;
            cin >> name >> type;

            auto cnt_index = type_to_index.find(type);

            if (cnt_index == type_to_index.end()) {
                cnt[types]++;
                type_to_index.insert_or_assign(type, types++);
            } else {
                cnt[cnt_index->second]++;
            }
        }

        for (int i = 0; i < types; i++) {
            combinations *= cnt[i] + 1;
        }

        cout << combinations - 1 << '\n';
    }

    return 0;
}