#include <bits/stdc++.h>
using namespace std;
struct node {
    int L, R;
};
bool cmp(node a, node b) {
    return a.R < b.R;
}
int getmaxx(vector<node>& a) {
    if (a.empty()) return 0;
    sort(a.begin(), a.end(), cmp);
    int maxnum = 0;
    for (const auto &itt : a) {
        maxnum = max(maxnum, itt.R);
    }
    set<int> adays;
    for (int day = 1; day <= maxnum; ++day) {
        adays.insert(day);
    }
    int cnt = 0;
    for (const auto &itt : a) {
        auto it = adays.lower_bound(itt.L);
        if (it != adays.end() && *it <= itt.R) {
            ++cnt;
            adays.erase(it);
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
        cin >> a[i].L >> a[i].R;
    }
    cout << getmaxx(a) << '\n';
    return 0;
}
