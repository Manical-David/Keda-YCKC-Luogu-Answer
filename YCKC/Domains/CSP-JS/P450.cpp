#include <bits/stdc++.h>
#define int long long
// #include <windows.h>
using namespace std;
signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> gems;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        gems.emplace_back(val, i);
    }
    sort(gems.begin(), gems.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });
    long long sumA = 0, sumB = 0;
    vector<int> ass(n);
    for (const auto& gem : gems) {
        int val = gem.first;
        int idx = gem.second;
        if (sumA <= sumB) {
            sumA += val;
            ass[idx] = 1;
        } else {
            sumB += val;
            ass[idx] = 0;
        }
    }
    for (int x : ass) {
        cout << x;
    }
    // cout << endl;
    // system("pause");
    return 0;
}
