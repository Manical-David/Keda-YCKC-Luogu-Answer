#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    vector<int> ans;
    int pos = 0;
    while (!a.empty()) {
        pos = (pos + m - 1) % a.size();
        ans.push_back(a[pos]);
        a.erase(a.begin() + pos);
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    return 0;
}
