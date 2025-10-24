#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    srand(time(0));
    int n = rand() % 501;
    cout << n << '\n';
    for(int i = 0; i < n; i++) {
        cout << rand() << ' ';
    }
    return 0;
}