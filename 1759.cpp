#include <bits/stdc++.h>

using namespace std;

vector<char> chs;
vector<char> selected;

void generate_password(int n, int depth, int i, int ja, int mo) {
    if (n == depth) {
        if (ja < 2 || mo < 1) return;
        for (char s : selected) cout << s;
        cout << '\n';
        return;
    }

    for (; i < chs.size() - n + depth + 1; i++) {
        selected.push_back(chs[i]);
        bool ismo = chs[i] == 'a' || chs[i] == 'e' || chs[i] == 'i' || chs[i] == 'o' || chs[i] == 'u';
        generate_password(n, depth + 1, i + 1, ja + !ismo, mo + ismo);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int l, c;
    cin >> l >> c;

    while (c--) {
        char ch;
        cin >> ch;
        chs.push_back(ch);
    }
    sort(chs.begin(), chs.end());
    generate_password(l, 0, 0, 0, 0);

    return 0;
}