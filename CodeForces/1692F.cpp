#include <bits/stdc++.h>
using namespace std;
bool p;
long long t, n, a[300010], num[20];
char ch;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        p = 0;
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            num[a[i] % 10]++;
        }
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                for (int k = 0; k <= 9; k++)
                    if ((i + j + k) % 10 == 3) {
                        if (i == j && i == k) {
                            if (num[i] >= 3)
                            // cout << 1 << '\n';
                                p = 1;
                            continue;
                        }
                        if (i == j) {
                            if (num[i] >= 2 && num[k] >= 1)
                            // cout << 1 << '\n';
                                p = 1;
                            continue;
                        }
                        if (i == k) {
                            if (num[i] >= 2 && num[j] >= 1)
                            // cout << 1 << '\n';
                                p = 1;
                            continue;
                        }
                        if (j == k) {
                            if (num[i] >= 1 && num[j] >= 2)
                                // cout << 1 << '\n';
                                p = 1;
                            continue;
                        }
                        if (num[i] >= 1 && num[j] >= 1) {
                            if (num[k] >= 1)
                            // cout << 1 << '\n';
                                p = 1;
                        }
                    }
        if (p) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
