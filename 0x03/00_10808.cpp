#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    char str[101];
    int cnt[27] = { 0, };
    scanf("%s", str);
    int i = 0;
    do {
        cnt[str[i] - 'a']++;
    } while(str[++i]);
    for (int i = 0; i < 26; i++)
        printf("%d ", cnt[i]);
    
    return 0;
}