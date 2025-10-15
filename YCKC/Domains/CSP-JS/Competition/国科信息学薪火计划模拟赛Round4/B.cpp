#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, m, T;
    cin >> n >> m >> T;
    string A0, B0;
    cin >> A0 >> B0;
    const unsigned long long maxn = 1e18;
    vector<unsigned long long> s(936);
    s[0] = n;
    s[1] = n + m;
    if (s[1] > maxn) {
        s[1] = maxn + 1;
    }
    for (int k = 2; k <= 935; ++k) {
        if (s[k-1] > maxn / 2) {
            s[k] = maxn + 1;
        } 
        else {
            s[k] = s[k-1] * 2;
        }
    }
    while (T--) {
        unsigned long long x;
        cin >> x;
        int k = 935;
        bool is_A = true;
        while (k > 0) {
            if (is_A) {
                unsigned long long len_prev_A;
                if (k - 1 == 0) {
                    len_prev_A = s[0];
                } 
                else {
                    len_prev_A = s[k - 1];
                }

                if (x <= len_prev_A) {
                    is_A = true;
                } 
                else {
                    x -= len_prev_A;
                    is_A = false;
                }
            } 
            else {
                unsigned long long len_prev_B;
                if (k - 1 == 0) {
                    len_prev_B = m;
                } 
                else {
                    len_prev_B = s[k - 1];
                }
                if (x <= len_prev_B) {
                    is_A = false;
                } 
                else {
                    x -= len_prev_B;
                    is_A = true;
                }
            }
            k--;
        }
        if (is_A) {
            cout << A0[x - 1] << '\n';
        } 
        else {
            cout << B0[x - 1] << '\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}