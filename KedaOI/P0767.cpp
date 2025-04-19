#include <bits/stdc++.h>
using namespace std;
string a[26] = {"A", "ABA", "ABACABA"};
void shengcheng() {
    for(int i = 3; i < 26; i++) {
        a[i] = a[i - 1] + (char)('A' + i) + a[i - 1];
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    shengcheng();
    int n;
    cin >> n;
    cout << a[n - 1];
    return 0;
}