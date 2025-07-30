#include <bits/stdc++.h>
using namespace std;
int getlength(vector<int>& trees, int h) {
    int sum = 0;
    for (const auto& height : trees) {
        if (height > h) {
            sum += height - h;
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    int l = 0, r = *max_element(trees.begin(), trees.end());
    int res = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int wod = getlength(trees, mid);
        if (wod >= m) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}