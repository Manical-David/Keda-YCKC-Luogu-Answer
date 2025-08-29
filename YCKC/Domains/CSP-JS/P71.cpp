#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            min_heap.push(x);
        } else if (a == 2) {
            cout << min_heap.top() << '\n';
        } else if (a == 3) {
            min_heap.pop();
        }
    }
    return 0;
}
