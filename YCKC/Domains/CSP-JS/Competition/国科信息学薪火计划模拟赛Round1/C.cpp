#include <bits/stdc++.h>
using namespace std;
constexpr int N = 12;
constexpr int MAXN = 1 << N;
int dp[MAXN];
vector<tuple<int, int, int>> ts;
bool checker(long long a, long long b, long long c) {
    return a + b > c;
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticls.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<long long> s(N);
        for (int i = 0; i < N; ++i) cin >> s[i];
        ts.clear();
        for (int i = 0; i < N; ++i) 
            for (int j = i + 1; j < N; ++j) 
                for (int k = j + 1; k < N; ++k) {
                    vector<long long> tmp = {s[i], s[j], s[k]};
                    sort(tmp.begin(), tmp.end());
                    if (checker(tmp[0], tmp[1], tmp[2])) {
                        ts.push_back(make_tuple(i, j, k));
                    }
                }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (dp[i] == -1) continue;
            for (auto &it : ts) {
                int a, b, c;
                tie(a, b, c) = it;
                if (!(i & (1 << a)) && !(i & (1 << b)) && !(i & (1 << c))) {
                    int tong = i | (1 << a) | (1 << b) | (1 << c);
                    if (dp[tong] < dp[i] + 1)
                        dp[tong] = dp[i] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (dp[i] > ans) ans = dp[i];
        }
        cout << ans << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}