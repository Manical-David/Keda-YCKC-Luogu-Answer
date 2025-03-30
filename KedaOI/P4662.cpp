#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 7;

int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%d", &a[i]);

    // [3, 5, 3, 4, 1, 2]
    // [0, 1, 2, 3, 4, 5]
    // slow = 3, fast = 4
    int slow = a[0], fast = a[a[0]];
    while (slow != fast) {
        slow = a[slow];
        fast = a[a[fast]];
    }
    // 快指针回到开头位置，然后每次走一步
    fast = 0;
    while (slow != fast) {
        fast = a[fast];
        slow = a[slow];
    }
    printf("%d\n", slow);
    return 0;
}