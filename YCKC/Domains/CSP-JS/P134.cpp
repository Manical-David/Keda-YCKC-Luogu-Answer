#include <bits/stdc++.h>
using namespace std;
bool isprime(long long a) {
    if (a < 2) return false;
    for (long long i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}
void dfs(vector<int>& b, int k, int c, long long a, int& cnt) {
    if (k == 0) {
        if (isprime(a)) {
            cnt++;
        }
        return;
    }
    for (int i = c; i <= b.size() - k; ++i) {
        dfs(b, k - 1, i + 1, a + b[i], cnt);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int cnt = 0;
    dfs(b, k, 0, 0, cnt);
    cout << cnt;
    return 0;
}
