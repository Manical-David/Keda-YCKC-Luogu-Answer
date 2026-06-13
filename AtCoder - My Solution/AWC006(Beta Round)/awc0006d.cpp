#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<pair<int,int> > seg(M);
    for (int i = 0; i < M; ++i) {
        cin >> seg[i].first >> seg[i].second;
    }
    sort(seg.begin(), seg.end());
    priority_queue<int> pq;
    int ans = 0, pos = 0, i = 0;
    while (pos < N) {
        while (i < M && seg[i].first <= pos + 1) {
            pq.push(seg[i].second);
            ++i;
        }
        if (pq.empty()) {
            cout << "-1\n";
            return 0;
        }
        int nxt = pq.top(); pq.pop();
        if (nxt <= pos) {
            cout << "-1\n";
            return 0;
        }
        ++ans;
        pos = nxt;
    }
    cout << ans << '\n';
    return 0;
}