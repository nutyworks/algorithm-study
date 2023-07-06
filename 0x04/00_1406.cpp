#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    list<char> l;
    string s;
    int n, cur = 0;
    
    cin >> s;
    for (auto c : s) {
        l.push_back(c);
    }
    auto cursor = l.end();

    cin >> n;

    while (n--) {
        char cmd;

        cin >> cmd;

        switch (cmd)
        {
            case 'L':
                if (cursor != l.begin()) cursor--;
                break;
            case 'D':
                if (cursor != l.end()) cursor++;
                break;
            case 'B':
                if (cursor != l.begin()) {
                    cursor--;
                    cursor = l.erase(cursor);
                }
                break;
            case 'P':
                char c;
                cin >> c;
                l.insert(cursor, c);
                break;
            default:
                break;
        }
    }

    for (auto c : l) cout << c;

    return 0;
}