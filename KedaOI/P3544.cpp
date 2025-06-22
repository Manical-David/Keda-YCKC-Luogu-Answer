#include <bits/stdc++.h>
using namespace std;
int n, target, ans = 0;
vector<int> a;
void dfs(int idx, int sum) {
    if (idx == n) {
        if (sum == target) ++ans;
        return;
    }
    dfs(idx + 1, sum + a[idx]);
    dfs(idx + 1, sum - a[idx]);
}

int main() {
    cin >> n >> target;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}