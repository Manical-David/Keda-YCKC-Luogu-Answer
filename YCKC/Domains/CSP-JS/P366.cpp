#include <bits/stdc++.h>
using namespace std;
int upper(const vector<int>& arr, int q) {
    int l = 0;
    int r = arr.size() - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= q) {
            res = mid + 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    while (m--) {
        int q;
        cin >> q;
        cout << upper(arr, q) << "\n";
    }
    return 0;
}