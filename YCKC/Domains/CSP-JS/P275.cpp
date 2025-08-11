#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    list<int> seq;
    unordered_map<int, list<int>::iterator> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        seq.push_back(x);
        pos[x] = --seq.end();
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto it = pos[a];
        auto ins = next(it);
        auto b_it = seq.insert(ins, b);
        pos[b] = b_it;
    }
    for (auto it = seq.begin(); it != seq.end(); ++it) {
        if (it != seq.begin()) {
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}
