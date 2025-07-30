#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> dancers(n);
    for (int i = 0; i < n; i++) {
        dancers[i] = i + 1;
    }
    int offset = 0;
    bool flipped = false;
    for (char c : s) {
        if (c == 'r') {
            offset = (offset + 1) % n;
        } else if (c == 'f') {
            flipped = !flipped;
        }
    }
    for (int i = 0; i < n; i++) {
        int pos = (i - offset + n) % n;
        if (flipped) {
            pos = n - 1 - pos;
        }
        cout << dancers[pos] << "\n";
    }

    return 0;
}