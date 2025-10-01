#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成随机01字符串，长度为n
string generate_coin_string(int n) {
    string s;
    for (int i = 0; i < n; ++i) {
        // 50%概率生成'0'或'1'
        s += (rand() % 2 == 0) ? '0' : '1';
    }
    return s;
}

int main() {
    // 初始化随机数种子，确保每次运行生成不同数据
    srand((unsigned int)time(0));
    
    // 生成测试数据的组数（可自行调整，这里生成10组）
    int T = 10;
    // 如需生成更多数据，可修改T的值，例如：
    // T = rand() % 20 + 1; // 随机生成1-20组数据
    
    while (T--) {
        // 生成n：1 ≤ n ≤ 300
        int n = rand() % 300 + 1;
        // 生成m：1 ≤ m ≤ n
        int m = rand() % n + 1;
        
        // 生成硬币序列
        string s = generate_coin_string(n);
        
        // 输出测试数据
        cout << s << endl;
        cout << m << endl;
    }
    
    return 0;
}