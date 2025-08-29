#include <bits/stdc++.h>
using namespace std;
bool check(int mid, const vector<int>& a, int L, int M) {
    int prev = 0;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] - prev < mid) {
            cnt++;
        } else {
            prev = a[i];
        }
    }
    if (L - prev < mid) {
        cnt++;
    }
    return cnt <= M;
}
int main() {
    int L, N, M;
    cin >> L >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int l = 1, r = L;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid, a, L, M)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return 0;
}