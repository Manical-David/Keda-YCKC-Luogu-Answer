#include <bits/stdc++.h>
using namespace std;
struct node {
    int st;
    int e;
};
bool cmp(node a, node b) {
    return a.e < b.e;
}
int solve(vector<node>& a) {
    if (a.empty()) return 0;
    sort(a.begin(), a.end(), cmp);
    int cnt = 1;
    int end = a[0].e;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i].st > end) {
            ++cnt;
            end = a[i].e;
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].st >> a[i].e;
    }
    cout << solve(a) << '\n';
    return 0;
}