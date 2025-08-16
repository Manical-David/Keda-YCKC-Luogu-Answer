#include <bits/stdc++.h>
using namespace std;
long long getx(vector<int> sa, vector<int> la, long long mid) {
    long long cnt = 0;
    int n = sa.size();
    for (int i = 0; i < n; i++) {
        long long minn = (mid + sa[i] - 1) / sa[i];
        auto it = lower_bound(la.begin(), la.end(), minn);
        cnt += la.end() - it;
    }
    return cnt;
}
long long fnd(vector<int> A, vector<int> B, int k) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long minn = (long long)A[0] * B[0];
    long long maxx = (long long)A.back() * B.back();
    vector<int> sa = A.size() <= B.size() ? A : B;
    vector<int> la = A.size() <= B.size() ? B : A;
    while (minn < maxx) {
        long long mid = minn + (maxx - minn + 1) / 2;
        long long cnt = getx(sa, la, mid);
        if (cnt >= k) {
            minn = mid;
        } else {
            maxx = mid - 1;
        }
    }
    return minn;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    vector<int> B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    cout << fnd(A, B, k) << '\n';
    return 0;
}