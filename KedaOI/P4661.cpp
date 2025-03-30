#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int odd = 1, even = 0; odd < n && even < n;) {
        if (a[n - 1] & 1) {
            swap(a[n - 1], a[odd]);
            odd += 2;
        } else {
            swap(a[n - 1], a[even]);
            even += 2;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}