#include <iostream>

int main() {
    for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; j < 4; j++) {
            int t;
            std::cin >> t;
            s += t;
        }
        if (s >= 4) {
            std::cout << "E\n";
        } else {
            std::cout << (char)(68 - s) << '\n';
        }
    }
}