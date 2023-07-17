#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;
vector<int> selected;

void generate_numbers(int n, int depth, int i) {
    if (n == depth) {
        for (int s : selected) cout << s << ' ';
        cout << '\n';
        return;
    }

    for (; i < numbers.size() - n + depth + 1; i++) {
        selected.push_back(numbers[i]);
        generate_numbers(n, depth + 1, i + 1);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        while (n--) {
            int t;
            cin >> t;
            numbers.push_back(t);
        }
        generate_numbers(6, 0, 0);
        numbers.clear();
        cout << '\n';
    }

    return 0;
}