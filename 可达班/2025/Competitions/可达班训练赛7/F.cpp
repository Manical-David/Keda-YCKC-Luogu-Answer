#include <bits/stdc++.h>
using namespace std;
vector<int> to_base3(int x, int n) {
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = x % 3;
        x /= 3;
    }
    return res;
}
int from_base3(const vector<int>& dd) {
    int res = 0;
    for (int i = dd.size() - 1; i >= 0; --i) {
        res = res * 3 + dd[i];
    }
    return res;
}
int mirror(int x, int n) {
    vector<int> dd = to_base3(x, n);
    for (int i = 0; i < n; ++i) {
        if (dd[i] == 1) dd[i] = 2;
        else if (dd[i] == 2) dd[i] = 1;
    }
    return from_base3(dd);
}
int main() {
    int n;
    string K;
    cin >> n >> K;
    int size = 1;
    for (int i = 0; i < n; ++i) size *= 3;
    vector<int> pos(size);
    for (int i = 0; i < size; ++i) pos[i] = i;
    int Rs = 0;
    bool Ss = false;
    for (char c : K) {
        if (c == 'R') {
            Rs = (Rs + 1) % size;
        } else { // 'S'
            for (int i = 0; i < size; ++i) {
                int m = mirror(i, n);
                if (i < m) {
                    swap(pos[i], pos[m]);
                }
            }
            if (Rs > 0) {
                vector<int> new_pos(size);
                for (int i = 0; i < size; ++i) {
                    new_pos[(i + Rs) % size] = pos[i];
                }
                pos = new_pos;
                Rs = 0;
            }
        }
    }
    if (Rs > 0) {
        vector<int> new_pos(size);
        for (int i = 0; i < size; ++i) {
            new_pos[(i + Rs) % size] = pos[i];
        }
        pos = new_pos;
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