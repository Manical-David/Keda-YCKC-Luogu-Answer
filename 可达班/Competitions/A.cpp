#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 计算相对于'A'的偏移量，处理循环后转换为字符
            char c = 'A' + (2 + i + j) % 26;
            cout << c;
        }
        cout << endl;
    }
    return 0;
}