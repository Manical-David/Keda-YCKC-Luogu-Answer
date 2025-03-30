#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n; // r
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a; // r
        bitset<10> binary(a); // bitset 10-2
        cout << binary << endl; // 01010 -> 0
    }
    return 0;
}