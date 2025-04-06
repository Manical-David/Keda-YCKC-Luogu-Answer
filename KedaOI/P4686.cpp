#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
int n;
char s[N];
int main() {
    scanf("%d%s", &n, s + 1);
    unordered_map<char, int> mp;
    char lastChar = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == lastChar) {
            sum += 1;
        } else {
            mp[lastChar] = max(sum, mp[lastChar]);
            lastChar = s[i];
            sum = 1;
        }
    }
    if (lastChar) {
        mp[lastChar] = max(sum, mp[lastChar]);
    }
    int res = 0;
    for (const auto &it : mp) {
        res += it.second;
    }
    printf("%d\n", res);
    return 0;
}