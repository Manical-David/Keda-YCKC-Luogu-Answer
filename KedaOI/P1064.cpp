#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    vector<int> nums(n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        s.insert(nums[i]);
    }
    cin >> m;
    vector<pair<int, int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        int a = nums[i];
        int b = m - a;
        if (a < b && s.count(b)) {
            res.emplace_back(a, b);
        }
    }
    for (auto &p : res) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}