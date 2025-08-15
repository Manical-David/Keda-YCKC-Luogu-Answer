#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.second < y.second;
    });
    int cnt = 0;
    int last = -2e9;
    for (auto &it : a) {
        int l = it.first, r = it.second;
        if (l > last) {
            cnt++;
            last = r;
        }
    }
    cout << cnt << '\n';
    return 0;
}