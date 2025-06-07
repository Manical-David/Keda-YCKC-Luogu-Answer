#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int mid = n;
    string left = s.substr(0, mid), right = s.substr(mid, mid);
    unordered_map<string, int> cnt;

    // 枚举左半部分所有染色方案
    for (int mask = 0; mask < (1 << mid); ++mask) {
        string black, white;
        for (int i = 0; i < mid; ++i) {
            if (mask & (1 << i))
                black += left[i];   // 染黑
            else
                white += left[i];   // 染白
        }
        cnt[black + "#" + white]++; // 统计每种方案出现次数
    }

    long long ans = 0;
    // 枚举右半部分所有染色方案
    for (int mask = 0; mask < (1 << mid); ++mask) {
        string black, white;
        for (int i = 0; i < mid; ++i) {
            if (mask & (1 << i))
                black += right[i];  // 染黑
            else
                white += right[i];  // 染白
        }
        string S1 = black;
        string S2 = white;
        reverse(S2.begin(), S2.end()); // 白色部分要反转
        string key = S2 + "#" + S1;    // 构造与左半部分匹配的key
        if (cnt.count(key))
            ans += cnt[key];
    }
    cout << ans << endl;
    return 0;
}