#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    vector<int> lis(n, 1);
    vector<int> lds(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[j] < h[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (h[j] < h[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        max_len = max(max_len, lis[i] + lds[i] - 1);
    }
    cout << n - max_len << endl;
    return 0;
}