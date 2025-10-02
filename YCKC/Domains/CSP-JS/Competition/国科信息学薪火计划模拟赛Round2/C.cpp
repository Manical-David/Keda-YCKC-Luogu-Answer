#include <bits/stdc++.h>
using namespace std;
class fwTrie { // 别问我为什么不用struct：因为刚学会
private:
    vector <long long> trie;
    int n;
public:
    fwTrie(int len) : n(len), trie(len + 2, 0) {}
    void g(int idx, long long val) {
        while (idx <= n) {
            trie[idx] += val;
            idx += idx & -idx;
        }
    }
    void genr(int l, int r, long long val) {
        g(l, val);
        if (r + 1 <= n) {
            g(r + 1, -val);
        }
    }
    long long q(int idx) {
        long long res = 0;
        while (idx > 0) {
            res += trie[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("index.in", "r", stdin);
    freopen("index.out", "w", stdout);
    int K, n;
    cin >> K >> n;
    vector <long long> a(n + 1); // a[1..n]
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    fwTrie ft(n); // 废物小trie
    for (int q = 0; q < K; ++q) {
        int l = 1, r = n;
        bool flag = false;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long g = a[mid] - mid + ft.q(mid);
            if (g == 0) {
                flag = true;
                break;
            } else if (g < 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
        if (q < K - 1) {
            int L, R, C;
            cin >> L >> R >> C;
            ft.genr(L, R, C);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}