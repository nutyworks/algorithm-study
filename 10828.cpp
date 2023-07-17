#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int stack[10000];
    int cursor = 0;

    while (n--) {
        string command;
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            stack[cursor++] = num;
        } else if (command == "pop") {
            if (cursor == 0) {
                cout << "-1\n";
            } else {
                cout << stack[--cursor] << '\n';
            }
        } else if (command == "size") {
            cout << cursor << '\n';
        } else if (command == "empty") {
            cout << ((cursor == 0) ? 1 : 0) << '\n';
        } else if (command == "top") {
            if (cursor == 0) {
                cout << "-1\n";
            } else {
                cout << stack[cursor - 1] << '\n';
            }
        }
    }

    return 0;
}