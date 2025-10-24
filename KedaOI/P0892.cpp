#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3 + 7, mod = 1e9 + 7;
int f[N], n;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }
    cout << f[n];
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e3 + 7, mod = 1e9 + 7;

int f[N], n;

int main() {
    /*
        4:
            1 + 1 + 1 + 1
            1 + 1 + 2
            2 + 2
            1 + 3
            4
    */
   /*
    scanf("%d", &n);

    // 恰好装满背包
    f[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j - i]) % mod;
        }
    }

    printf("%d\n", f[n]);
    return 0;
}
*/