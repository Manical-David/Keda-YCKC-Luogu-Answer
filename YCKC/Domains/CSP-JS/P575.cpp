#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<int> char_pos[26];
    for (int i = 0; i < N; ++i) {
        char c = S[i];
        char_pos[c - 'a'].insert(i + 1);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            char c;
            cin >> i >> c;
            char org = S[i - 1];
            if (org == c) {
                continue;
            }
            char_pos[org - 'a'].erase(i);
            char_pos[c - 'a'].insert(i);
            S[i - 1] = c;
        } else {
            int l, r;
            cin >> l >> r;
            int cnt = 0;
            for (int i = 0; i < 26; ++i) {
                auto it = char_pos[i].lower_bound(l);
                if (it != char_pos[i].end() && *it <= r) {
                    cnt++;
                }
            }
            
            cout << cnt << '\n';
        }
    }
    return 0;
}