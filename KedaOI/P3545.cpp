#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    int ans_s = h * 3600 + m * 60 + s;
    ans_s += k;
    int new_h = ans_s / 3600;
    int new_m = (ans_s % 3600) / 60;
    int new_s = ans_s % 60;
    cout << new_h << " " << new_m << " " << new_s << endl;
    return 0;
}
