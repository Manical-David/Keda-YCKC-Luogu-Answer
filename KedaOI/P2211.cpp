#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    unordered_map<char, int> freq; // 记录窗口内每个字符的频率
    int left = 0, right = 0;       // 滑动窗口的左右边界
    int max_size = 0;            // 满足条件的最长子串长度
    while (right < n) {
        // 扩展右边界
        freq[s[right]]++;
        right++;

        // 如果窗口内某个字符的频率超过 m，收缩左边界
        while (freq[s[right - 1]] > m) {
            freq[s[left]]--;
            left++;
        }

        // 更新最大长度
        max_size = max(max_size, right - left);
    }

    cout << max_size << endl;
    return 0;
}