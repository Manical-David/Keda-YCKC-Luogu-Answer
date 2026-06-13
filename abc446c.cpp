#include <bits/stdc++.h>
using namespace std;
struct egs {
    int day;
    int cnt;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, D;
        cin >> N >> D;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        vector<egs> st(N);
        int f = 0, b = 0;
        int tt = 0;
        
        for (int day = 1; day <= N; day++) {
            if (A[day - 1] > 0) {
                st[b] = {day, A[day - 1]};
                b++;
                tt += A[day - 1];
            }
            int n = B[day - 1];
            while (n > 0) {
                egs& bat = st[f];
                if (bat.cnt <= n) {
                    n -= bat.cnt;
                    tt -= bat.cnt;
                    f++;
                } else {
                    bat.cnt -= n;
                    tt -= n;
                    n = 0;
                }
            }
            int thr = day - D;
            while (f < b && st[f].day <= thr) {
                tt -= st[f].cnt;
                f++;
            }
        }
        cout << tt << "\n";
    }
    return 0;
}