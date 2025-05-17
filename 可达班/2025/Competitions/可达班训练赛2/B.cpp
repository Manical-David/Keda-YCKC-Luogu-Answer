#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int N, Q;
    cin >> N >> Q;
    vector<pii> bef;
    bef.reserve((size_t)N + Q + 5);
    for (int i = N; i >= 1; --i) {
        bef.emplace_back(i, 0);
    }
    int t = N - 1;
    auto move = [&](char C) {
        switch (C) {
            case 'L': return pii{-1,  0};
            case 'R': return pii{+1,  0};
            case 'U': return pii{ 0, +1};
            case 'D': return pii{ 0, -1};
        }
        return pii{0,0}; // 不可能
    };
    ostringstream output; // 定义输入输出流构造字符串
    for (int iq = 0; iq < Q; ++iq) {
        int op; 
        cin >> op;
        if (op == 1) {
            char C;
            cin >> C;
            pii head = bef[t];
            pii d = move(C);
            // 新头
            bef.emplace_back(head.first + d.first,
                            head.second + d.second);
            ++t;
        }
        else {
            int p;
            cin >> p;
            int idx = t - (p - 1);
            const auto &pos = bef[idx];
            output << pos.first << ' ' << pos.second << '\n'; // 输出数据至output
        }
    }
    // 一次性输出，避免频繁 flush
    cout << output.str();
    return 0;
}
