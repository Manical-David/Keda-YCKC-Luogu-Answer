#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, C;
    cin >> N >> C;
    int w[1005];
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }
    int maxCnt = 0;
    for (int s = 0; s < N; ++s) {
        int tong = 0;
        int cnt = 0;
        for (int i = s; i < N; ++i) {
            if (tong + w[i] <= C) {
                tong += w[i];
                cnt++;
            } else {
                continue;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << endl;
    return 0;
}