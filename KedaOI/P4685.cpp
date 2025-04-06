#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
char s[N], t[N];
int main() {
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1, j = 1; i <= n; i++, j++) {
        while (j <= m && t[j] != s[i]) j += 1;
        printf("%d ", j);
    }
    return 0;
}