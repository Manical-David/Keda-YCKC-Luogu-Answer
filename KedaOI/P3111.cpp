#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& a) {
    int n = a.size();
    if (n < 2) return 0;
    vector<int> hold(n, 0);
    vector<int> not_hold(n, 0);
    vector<int> cooldown(n, 0);
    hold[0] = -a[0]; 
    not_hold[0] = 0;
    cooldown[0] = 0;
    for (int i = 1; i < n; ++i) {
        hold[i] = max(hold[i - 1], not_hold[i - 1] - a[i]);
        not_hold[i] = max(not_hold[i - 1], cooldown[i - 1]);
        cooldown[i] = hold[i - 1] + a[i];
    }

    return max(not_hold[n - 1], cooldown[n - 1]);
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}
