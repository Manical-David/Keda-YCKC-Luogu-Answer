#include <bits/stdc++.h>
using namespace std;
int solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    int l = 0, r = n - 1;
    int alice = 0, bob = 0;
    int maxx = 0;
    while (l <= r) {
        if (alice < bob) {
            alice += w[l];
            l++;
        } else if (alice > bob) {
            bob += w[r];
            r--;
        } else {
            maxx = l + (n - r - 1);
            alice += w[l];
            l++;
        }
    }
    if (alice == bob) {
        maxx = l + (n - r - 1);
    }
    return maxx;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}