#include <bits/stdc++.h>
using namespace std;
struct p {
    long long t;
    long long f;
} q[200010];
bool cmp(p x, p y) {
    return x.t * (x.f + y.f) + y.t * y.f < y.t * (x.f + y.f) + x.t * x.f;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i].t >> q[i].f;
    }
    sort(q + 1, q + 1 + n, cmp);
    long long time = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        time += q[i].t;
        sum += time * q[i].f;
    }
    cout << sum;
    return 0;
}