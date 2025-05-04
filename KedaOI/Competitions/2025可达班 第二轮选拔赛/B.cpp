#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'L') {
            sum++;
        }
    }
    int min_ = sum;
    for (int i = k; i < n; ++i) { // lr大派对
        if (s[i - k] == 'L') {
            sum--;  // 移除左侧的
        }
        if (s[i] == 'L') {
            sum++;  // 加入右侧的
        }
        min_ = min(min_, sum);
    }
    cout << min_ << endl;
    return 0;
}