#include <bits/stdc++.h>
using namespace std;
int getmaxn(unsigned long long x) {
    if (x == 0) return -1;
    int pos = 0;
    while (x > 1) {
        x >>= 1;
        pos++;
    }
    return pos;
}
void solve() {
    unsigned long long N;
    cin >> N;
    if (N < 7) {
        cout << "-1\n";
        return ;
    }
    int m = getmaxn(N);
    unsigned long long maxx = 0;
    for (int a = m; a >= 2; a--) {
        unsigned long long mask_a = 1ULL << a;
        if (mask_a > N) return ;
        int max_b = min(a - 1, getmaxn(N - mask_a));
        for (int b = max_b; b >= 1; b--) {
            unsigned long long mask_b = 1ULL << b;
            unsigned long long sum_ab = mask_a + mask_b;
            if (sum_ab > N) return ;
            int max_c = min(b - 1, getmaxn(N - sum_ab));
            if (max_c >= 0) {
                unsigned long long tong = sum_ab + (1ULL << max_c);
                if (tong > maxx) {
                    maxx = tong;
                }
            }
        }
    }
    cout << maxx << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("cake.in", "r", stdin);
    freopen("cake.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
