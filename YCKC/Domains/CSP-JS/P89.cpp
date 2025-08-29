#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<int> le(N + 1, 0);
    vector<int> ri(N + 1, 0);
    vector<bool> del(N + 1, false);
    le[1] = 0;
    ri[1] = 0;
    for (int i = 2; i <= N; ++i) {
        int k, p;
        cin >> k >> p;
        if (p == 0) {
            int k_left = le[k];
            le[i] = k_left;
            ri[i] = k;
            le[k] = i;
            if (k_left != 0) {
                ri[k_left] = i;
            }
        } else {
            int k_right = ri[k];
            ri[i] = k_right;
            le[i] = k;
            ri[k] = i;
            if (k_right != 0) {
                le[k_right] = i;
            }
        }
    }
    int head = 1;
    while (le[head] != 0) {
        head = le[head];
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        if (!del[x]) {
            del[x] = true;
            int l = le[x];
            int r = ri[x];
            if (l != 0) ri[l] = r;
            if (r != 0) le[r] = l;
            if (x == head) head = r;
        }
    }
    bool first = true;
    int ans = head;
    while (ans != 0) {
        if (!first) {
            cout << " ";
        }
        first = false;
        cout << ans;
        ans = ri[ans];
    }
    cout << '\n';
    return 0;
}
