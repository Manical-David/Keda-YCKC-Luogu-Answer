#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    int correct = 0;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line); // 小用stream，因为懒
        long long a, b, c;
        char op, eq;
        ss >> a >> op >> b >> eq >> c; // 模拟cin
        long long res = 0;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break; // 题目保证合法，b 不为 0
        }
        if (res == c) ++correct;
    }
    double ans = 100.0 * correct / n;
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
