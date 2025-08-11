#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long m;
    cin >> n >> m;
    vector<int> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
    }
    int low = 0;
    int h = *max_element(trees.begin(), trees.end());
    int ans = 0;
    while (low <= h) {
        int mid = low + (h - low) / 2;
        long long tol = 0;
        for (int h : trees) {
            if (h > mid) {
                tol += h - mid;
                if (tol >= m) break;
            }
        }
        if (tol >= m) {
            ans = mid;
            low = mid + 1;
        } else h = mid - 1;
    }
    cout << ans << endl;
    return 0;
}