#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    // 错位对的计数
    int pattern1_misplaced_A = 0;  // 对应 'A' 应该在 'B' 的位置
    int pattern1_misplaced_B = 0;  // 对应 'B' 应该在 'A' 的位置

    int pattern2_misplaced_A = 0;  // 对应 'A' 应该在 'B' 的位置
    int pattern2_misplaced_B = 0;  // 对应 'B' 应该在 'A' 的位置

    // 遍历字符串，统计两个模式下的错位对
    for (int i = 0; i < 2 * N; i++) {
        if (i % 2 == 0) {  // 偶数位置
            if (S[i] != 'A') pattern1_misplaced_A++;  // 模式1 期望是 'A'，实际是 'B'
            if (S[i] != 'B') pattern2_misplaced_B++;  // 模式2 期望是 'B'，实际是 'A'
        } else {  // 奇数位置
            if (S[i] != 'B') pattern1_misplaced_B++;  // 模式1 期望是 'B'，实际是 'A'
            if (S[i] != 'A') pattern2_misplaced_A++;  // 模式2 期望是 'A'，实际是 'B'
        }
    }

    // 交换次数等于错位的 'A' 和 'B' 配对的数量
    // 每次交换能同时解决一个错位的 'A' 和 'B'
    int swaps_pattern1 = max(pattern1_misplaced_A, pattern1_misplaced_B);
    int swaps_pattern2 = max(pattern2_misplaced_A, pattern2_misplaced_B);

    // 最小交换次数
    cout << min(swaps_pattern1, swaps_pattern2) << endl;

    return 0;
}
