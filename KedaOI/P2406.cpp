#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e7 + 7;
int n, val, a[N];
int main() {
    scanf("%d %d", &n, &val);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int slow = 1;
    for (int fast = 1; fast <= n; fast++) {
        if (a[fast] != val) a[slow++] = a[fast];
    }
    for (int i = 1; i < slow; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}