#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = n - 1, j = n - 2;
    int last = -1;
    bool flag = true;
    while (i >= 0 && j >= 0) {
        if (a[i] <= b[j]) {
            --i;
            --j;
        } else {
            last = a[i];
            --i;
        }
    }
    if (i >= 0) {
        last = a[i];
    }
    if (last == -1) {
        last = 1;
    }
    vector<int> new_b = b;
    new_b.push_back(last);
    sort(new_b.begin(), new_b.end());
    i = n - 1;
    j = n - 1;
    flag = true;
    while (i >= 0 && j >= 0) {
        if (a[i] <= new_b[j]) {
            --i;
            --j;
        } else {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << last << '\n';
    } 
    else {
        cout << -1 << '\n';
    }
    return 0;
}
