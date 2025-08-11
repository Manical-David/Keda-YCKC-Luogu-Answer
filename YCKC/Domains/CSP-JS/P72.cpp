#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    deque<int> dq[101];
    int q;
    cin >> q;
    while (q--) {
        string op;
        int a, x;
        cin >> op;
        
        if (op == "push_back") {
            cin >> a >> x;
            dq[a].push_back(x);
        } 
        else if (op == "pop_back") {
            cin >> a;
            if (!dq[a].empty()) {
                dq[a].pop_back();
            }
        } 
        else if (op == "push_front") {
            cin >> a >> x;
            dq[a].push_front(x);
        } 
        else if (op == "pop_front") {
            cin >> a;
            if (!dq[a].empty()) {
                dq[a].pop_front();
            }
        } 
        else if (op == "size") {
            cin >> a;
            cout << dq[a].size() << '\n';
        } 
        else if (op == "front") {
            cin >> a;
            if (!dq[a].empty()) {
                cout << dq[a].front() << '\n';
            }
        } 
        else if (op == "back") {
            cin >> a;
            if (!dq[a].empty()) {
                cout << dq[a].back() << '\n';
            }
        }
    }
    return 0;
}