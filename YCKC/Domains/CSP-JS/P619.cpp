#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    deque <int> q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push_back") {
            int x;
            cin >> x;
            q.push_back(x);
        }
        else if(str == "pop_back" && !q.empty()) {
            q.pop_back();
        }
        else if(str == "push_front") {
            int x;
            cin >> x;
            q.push_front(x);
        }
        else if(str == "pop_front" && !q.empty()) {
            q.pop_front();
        }
        else if(str == "size") {
            cout << q.size() << '\n';
        }
        else if(str == "front" && !q.empty()) {
            cout << q.front() << '\n';
        }
        else if(str == "back" && !q.empty()) {
            cout << q.back() << '\n';
        }
    }
    return 0;
} // stack <int> a;