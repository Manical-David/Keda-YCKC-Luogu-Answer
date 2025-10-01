#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 10000000000000000000ULL;
int 检查的(int b, int exp) {
    int 结果 = 1;
    for (int i = 0; i < exp; ++i) {
        if (结果 > N / b) { 
            return N + 1;
        }
        结果 *= b;
    }
    return 结果;
}
signed main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int B1, D1, B2, D2;
    cin >> B1 >> D1 >> B2 >> D2;
    int 数值最低一 = 检查的(B1, D1 - 1);
    int 数值最高1 = 检查的(B1, D1);
    if (数值最高1 > N) {
        数值最高1 = N;
    } else {
        数值最高1--;
    }
    int 数值最低2 = 检查的(B2, D2 - 1);
    int 数值最高2 = 检查的(B2, D2);
    if (数值最高2 > N) {
        数值最高2 = N;
    } else {
        数值最高2--;
    }
    int 答案最低 = max(数值最低一, 数值最低2);
    int 答案最高 = min(数值最高1, 数值最高2);
    int 结果 = 0;
    if (答案最低 <= 答案最高) {
        结果 = 答案最高 - 答案最低 + 1;
    }
    cout << 结果 << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}