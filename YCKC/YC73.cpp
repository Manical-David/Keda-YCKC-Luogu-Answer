#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    cout << "Christmas ";
    for(int i = 0; i < abs(n - 25); i++) {
        cout << "Eve ";
    }
    return 0;
}