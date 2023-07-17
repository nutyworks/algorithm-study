#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, queue[10000], head = 0, tail = 0;

    cin >> n;

    while (n--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            queue[tail++] = num;

            continue;
        } else if (cmd == "pop") {
            if (tail - head == 0) {
                cout << "-1";
            } else {
                cout << queue[head++];
            }
        } else if (cmd == "size") {
            cout << tail - head;
        } else if (cmd == "empty") {
            cout << ((tail - head == 0) ? 1 : 0);
        } else if (cmd == "front") {
            if (tail - head == 0) {
                cout << "-1";
            } else {
                cout << queue[head];
            }
        } else if (cmd == "back") {
            if (tail - head == 0) {
                cout << "-1";
            } else {
                cout << queue[tail - 1];
            }
        }

        cout << '\n';
    }
}