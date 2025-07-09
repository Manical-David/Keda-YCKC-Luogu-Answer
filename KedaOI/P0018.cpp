#include <bits/stdc++.h>
using namespace std;
void cmp(const string &b, vector<int> &prefix) {
    int m = b.size();
    prefix.resize(m);
    int k = -1;
    prefix[0] = k;
    for (int q = 1; q < m; ++q) {
        while (k >= 0 && b[k + 1] != b[q]) {
            k = prefix[k];
        }
        if (b[k + 1] == b[q]) {
            k++;
        }
        prefix[q] = k;
    }
}
int cnts(const string &a, const string &b) {
    int n = a.size();
    int m = b.size();
    vector<int> prefix;
    cmp(b, prefix);
    int cnt = 0;
    int q = -1;
    for (int i = 0; i < n; ++i) {
        while (q >= 0 && b[q + 1] != a[i]) {
            q = prefix[q];
        }
        if (b[q + 1] == a[i]) {
            q++;
        }
        if (q == m - 1) {
            cnt++;
            q = prefix[q];
        }
    }
    return cnt;
}
int main() {
    string a, b;
    cin >> a >> b;
    int ans = cnts(a, b);
    cout << ans << endl;
    return 0;
}