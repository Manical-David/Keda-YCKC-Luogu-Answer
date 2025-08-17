#include <bits/stdc++.h>
using namespace std;
int solve(int a, int n) {
    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
    unordered_set<int> seen;
    pq.push(a);
    seen.insert(a);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = pq.top();
        pq.pop();
        int next1 = 2 * ans + 1;
        int next2 = 3 * ans + 1;
        if (seen.find(next1) == seen.end()) {
            seen.insert(next1);
            pq.push(next1);
        }
        if (seen.find(next2) == seen.end()) {
            seen.insert(next2);
            pq.push(next2);
        }
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, n;
        cin >> a >> n;
        cout << solve(a, n) << '\n';
    }
    return 0;
}
