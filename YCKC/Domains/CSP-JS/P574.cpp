#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> q;
    while (Q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            q.push(x);
        } else if (c == 2) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (c == 3) {
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}
