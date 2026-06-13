#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n;
    list<int> a;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k, x;
        cin >> k >> x;
        auto it = a.begin();
        advance(it, k);
        a.insert(it, x);
    }
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) {
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}