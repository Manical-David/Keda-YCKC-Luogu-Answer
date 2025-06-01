#include <bits/stdc++.h>
using namespace std;
constexpr int N = 37;
int n, m, cnt, val[N], damage[N];
int main() {
    scanf("%d %d %d", &n, &m, &cnt);
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);
    for (int i = 0; i < n; i++) scanf("%d", &damage[i]);
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        bitset<N> st = i;
        int tmpVal = 0, nowCnt = 0, nowM = m;
        for (int j = 0; j < n; j++) {
            if (st[j] == 1) {
                nowCnt += 1;
                tmpVal += val[j];
            } else {
                nowM -= damage[j];
            }
            if (nowM <= 0) break;
        }
        if (nowCnt == cnt) res = max(res, tmpVal);
    }
    printf("%d\n", res);
    return 0;
}