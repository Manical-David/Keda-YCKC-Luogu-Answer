#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    cout << bool((n / 10) > 0 && n / 10 < 10);
    return 0;
}