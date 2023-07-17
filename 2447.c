#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            int empty = 0, tx = x, ty = y;
            for (int i=8;--i;tx=(tx+2)/3,ty=(ty+2)/3) {
                empty += tx%3==2 && ty%3==2;
            }
            if (empty) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        puts("");
    }

    return 0;
}