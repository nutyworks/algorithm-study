#include <stdio.h>

int main() {
    int a[26], n;
    int *chs = a - 'a';
    char s1[1001], s2[1001];

    scanf("%d", &n);

    while (n--) {
        char c;
        int possible = 1;

        scanf(" %s %s", s1, s2);

        for (int i = 0; i < 26; i++) a[i] = 0;

        for (int i = 0; s1[i]; i++) {
            chs[s1[i]]++;
        }

        for (int i = 0; s2[i]; i++) {
            chs[s2[i]]--;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) possible = 0;
        }

        if (possible) printf("Possible\n");
        else printf("Impossible\n");
    }

    return 0;
}