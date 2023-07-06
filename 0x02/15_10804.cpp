#include <iostream>

void reverse(int *cards, int start_inclusive, int end_inclusive) {
    int to_reverse = end_inclusive - start_inclusive + 1, t;
    for (int i = start_inclusive - 1; i < start_inclusive + to_reverse / 2 - 1; i++) {
        int index1 = i, index2 = start_inclusive + end_inclusive - i - 2;
        
        t = cards[index1];
        cards[index1] = cards[index2];
        cards[index2] = t;
    }
}

int main() {
    int cards[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                      11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    for (int i = 0; i < 10; i++) {
        int start, end;
        std::cin >> start >> end;
        reverse(cards, start, end);
    }

    for (int i = 0; i < 20; i++) {
        std::cout << cards[i] << ' ';
    }

    return 0;
}
