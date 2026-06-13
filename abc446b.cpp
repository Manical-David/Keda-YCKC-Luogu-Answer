#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<bool> ch(M + 1, false);
    vector<int> ans(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;
        vector<int> ls(L);
        for (int j = 0; j < L; j++) {
            cin >> ls[j];
        }
        bool stt = false;
        for (int j : ls) {
            if (!ch[j]) {
                ans[i] = j;
                ch[j] = true;
                stt = true;
                break;
            }
        }
        if (!stt) {
            ans[i] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}