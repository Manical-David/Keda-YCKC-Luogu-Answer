#include <bits/stdc++.h>
using namespace std;
vector<string> a;
bool safe(vector<int>& queen, int x, int y) {
    for (int i = 0; i < x; i++) {
        if (queen[i] == y || abs(x - i) == abs(y - queen[i])) {
            return false;
        }
    }
    return true;
}
void print(vector<int>& queen, int x) {
    if (x == 8) {
        string s;
        for (int y : queen) {
            s += to_string(y + 1);
        }
        a.push_back(s);
        return;
    }
    for (int y = 0; y < 8; y++) {
        if (safe(queen, x, y)) {
            queen[x] = y;
            print(queen, x + 1);
        }
    }
}
void xy() {
    vector<int> queen(8);
    print(queen, 0);
    sort(a.begin(), a.end());
}
int main() {
    xy();
    int n;
    cin >> n;
    while (n--) {
        int q;
        cin >> q;
        cout << a[q - 1] << '\n';
    }
    return 0;
}
