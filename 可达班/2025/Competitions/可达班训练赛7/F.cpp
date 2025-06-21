#include <bits/stdc++.h>
using namespace std;
vector <int> to_base3(int x, int n) {
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = x % 3;
        x /= 3;
    }
    return res;
}
int from_base3(const vector<int>& digits) {
    int res = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
        res = res * 3 + digits[i];
    }
    return res;
}
int mirror(int x, int n) {
    vector<int> digits = to_base3(x, n);
    for (int i = 0; i < n; ++i) {
        if (digits[i] == 1) digits[i] = 2;
        else if (digits[i] == 2) digits[i] = 1;
    }
    return from_base3(digits);
}
int main() {
    int n;
    string K;
    cin >> n >> K;
    int size = 1;
    for (int i = 0; i < n; ++i) size *= 3;
    vector<int> pos(size);
    for (int i = 0; i < size; ++i) pos[i] = i;
    vector<int> mirror_map(size);
    for (int i = 0; i < size; ++i) {
        mirror_map[i] = mirror(i, n);
    }
    for (char c : K) {
        if (c == 'S') {
            for (int i = 0; i < size; ++i) {
                if (i < mirror_map[i]) {
                    swap(pos[i], pos[mirror_map[i]]);
                }
            }
        } else {
            vector<int> new_pos(size);
            for (int i = 0; i < size; ++i) {
                new_pos[(i + 1) % size] = pos[i];
            }
            pos = new_pos;
        }
    }
    vector<int> ans(size);
    for (int i = 0; i < size; ++i) {
        ans[pos[i]] = i;
    }
    for (int i = 0; i < size; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
