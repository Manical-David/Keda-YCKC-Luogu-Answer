#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<long long> c(N), pre(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        int k = 0;
        int x = A;
        while (x % 2 == 0) {
            x /= 2;
            k++;
        }
        a[i] = x;
        c[i] = 1LL << k;
    }
    pre[0] = c[0];
    for (int i = 1; i < N; ++i) {
        pre[i] = pre[i-1] + c[i];
    }
    int Q;
    cin >> Q;
    int pos = 0;
    while (Q--) {
        long long X;
        cin >> X;
        while (pos < N && pre[pos] < X) {
            pos++;
        }
        cout << a[pos] << '\n';
    }

    return 0;
}