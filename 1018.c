#include <stdio.h>
#include <stdlib.h>

int count_illegals(char *board, int width, int y, int x);

int main() {
    int h, w;
    scanf("%d%d", &h, &w);

    char *board = malloc(h * w * sizeof(char));

    for (int i = 0; i < h * w; i++) {
        char c;
        scanf(" %c", &c);
        board[i] = c & 1;
    }

    int calc_h = h - 7, calc_w = w - 7, min = 32;

    for (int i = 0; i < calc_h; i++) {
        for (int j = 0; j < calc_w; j++) {
            int result = count_illegals(board, w, i, j);
            min = result < min ? result : min;
        }
    }

    printf("%d", min);

    free(board);
}

int count_illegals(char *board, int width, int y, int x) {
    char expected_color = 0;
    char c1 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[(y + i) * width + x + j] ^ expected_color) {
                c1++;
            }
            expected_color ^= 1;
        }
        expected_color ^= 1;
    }
    return c1 < 32 ? c1 : 64 - c1;
}