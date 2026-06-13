#include <bits/stdc++.h>
using namespace std;
long long m_cnt(vector<int>& arr, int l, int m, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = m + 1, k = 0;
    long long cnt = 0;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            cnt += (m - i + 1);
            tmp[k++] = arr[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = arr[i++];
    }
    while (j <= r) {
        tmp[k++] = arr[j++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = tmp[i - l];
    }
    return cnt;
}
long long msc(vector<int>& arr, int l, int r) {
    long long inv_cnt = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv_cnt += msc(arr, l, m);
        inv_cnt += msc(arr, m + 1, r);
        inv_cnt += m_cnt(arr, l, m, r);
    }
    return inv_cnt;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = msc(a, 0, n - 1);
    cout << ans << '\n';
    return 0;
}