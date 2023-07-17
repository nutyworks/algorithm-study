#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        list<char> keys;
        auto cursor = keys.end();

        for (char ch : s) {
            switch (ch) {
                case '<': {
                    if (cursor == keys.begin()) break;
                    cursor--;
                    break;
                }
                case '>': {
                    if (cursor == keys.end()) break;
                    cursor++;
                    break;
                }
                case '-': {
                    if (cursor == keys.begin()) break;
                    cursor--;
                    cursor = keys.erase(cursor);
                    break;
                }
                default: {
                    keys.insert(cursor, ch);
                    break;
                }
            }
        }

        for (char key : keys) cout << key;
        cout << '\n';
    }

    return 0;
}