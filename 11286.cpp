#include <bits/stdc++.h>

using namespace std;

struct abscmp {
    bool operator()(const int &x, const int &y) const {
        if (abs(x) == abs(y)) return x > y;
        else return abs(x) > abs(y);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int, vector<int>, abscmp> heap;
    int n;
    cin >> n;

    while (n--) {
        int i;
        cin >> i;

        if (i == 0) {
            if (heap.empty()) {
                cout << "0\n";
            } else {
                cout << heap.top() << '\n';
                heap.pop();
            }
        } else {
            heap.push(i);
        }
    }

    return 0;
}