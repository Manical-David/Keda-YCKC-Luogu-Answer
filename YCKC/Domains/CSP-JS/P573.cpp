#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    long long L;
    int Q;
    cin >> L >> Q;
    set<long long> cuts = {0, L};
    while (Q--) {
        int c;
        long long x;
        cin >> c >> x;
        if (c == 1) {
            cuts.insert(x);
        } 
        else {
            auto it = cuts.upper_bound(x);
            long long r = *it;
            --it;
            long long l = *it;
            cout << r - l << '\n';
        }
    }
    return 0;
}