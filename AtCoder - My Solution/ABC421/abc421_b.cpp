#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    int i = 0;
    while (i < s.size() && s[i] == '0') {
        i++;
    }
    if (i == s.size()) {
        return 0;
    }
    s = s.substr(i);
    return stoll(s);
}
int main() {
    long long X, Y;
    cin >> X >> Y;
    long long a[11];
    a[1] = X;
    a[2] = Y;
    for (int i = 3; i <= 10; ++i) {
        a[i] = f(a[i - 1] + a[i - 2]);
    }
    cout << a[10] << '\n';
    return 0;
}
