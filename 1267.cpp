#include <iostream>

int main() {
    int y = 0, m = 0, n;

    std::cin >> n;

    while (n--) {
        int s;
        std::cin >> s;

        y += (s + 30) / 30 * 10;
        m += (s + 60) / 60 * 15;
    }

    if (y == m) {
        std::cout << "Y M " << y;
    } else if (y < m) {
        std::cout << "Y " << y;
    } else {
        std::cout << "M " << m;
    }

    return 0;
}