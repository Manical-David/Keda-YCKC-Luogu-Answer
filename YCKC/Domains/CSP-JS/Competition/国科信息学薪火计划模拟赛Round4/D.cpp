#include <bits/stdc++.h>
using namespace std;
bool canWin(int n, long long m, long long k, vector<long long>& a) {
    sort(a.begin(), a.end());
    long long cur = m;
    for (int i = 0; i < n; ++i) {
        if (cur >= a[i]) {
            continue;
        } 
        else if (cur == a[i] - 1 && k > 0) {
            cur += 1;
            k--;
        } 
        else if (cur < a[i]) {
            if (k == 0) {
                return false;
            }
            long long bin = a[i] - cur;
            long long add = min(k, bin);
            cur += add;
            k--;
            if (cur < a[i]) {
                return false;
            }
        }
    }
    return true;
}
void solve() {
    int n;
    long long m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool win = true;
    long long cur = m;
    for (int i = 0; i < n; ++i) {
        if (cur > a[i]) {
            continue;
        } 
        else if (cur == a[i]) {
            if (k > 0) {
                cur += min(k, (i < n - 1) ? (a[i + 1] - a[i]) : k);
                k--;
            }
        } 
        else {
            if (k == 0) {
                win = false;
                break;
            }
            long long bin = a[i] - cur;
            long long add = min(k, bin);
            cur += add;
            k--;
            if (cur < a[i]) {
                win = false;
                break;
            }
        }
    }
    if (win) {
        cout << "big win very win\n";
    } 
    else {
        cout << "manba out\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("solo.in", "r", stdin);
    freopen("solo.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 这一道题又简单起来了