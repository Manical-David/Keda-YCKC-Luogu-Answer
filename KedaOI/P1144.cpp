#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
int findMinPrime(int X) {
    string s = to_string(X);
    for (int len = 1; len <= 4; ++len) { // 假设最多添加4位数字
        for (int num = 0; num < pow(10, len); ++num) {
            string append = to_string(num);
            if (append.size() < len) {
                append = string(len - append.size(), '0') + append;
            }
            if (append[0] == '0') continue; // 避免前导0
            string candidate = s + append;
            int n = stoi(candidate);
            if (isPrime(n)) {
                return n;
            }
        }
    }
    return -1; // 理论上不会执行到这里，因为至少可以添加1位数字
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int X;
        cin >> X;
        cout << findMinPrime(X) << endl;
    }
    return 0;
}