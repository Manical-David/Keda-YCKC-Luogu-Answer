#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            min_heap.push(x);
        } else if (op == 2) {
            cout << min_heap.top() << '\n';
        } else if (op == 3) {
            min_heap.pop();
        }
    }
    return 0;
}