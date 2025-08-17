#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n;
    cin >> n;
    queue <int> q;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if(str == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(str == "pop" && !q.empty()) {
            q.pop();
        }
        else if(str == "empty") {
            if(q.empty()) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(str == "query" && !q.empty()) {
            cout << q.front() << '\n';
        }
    }
    return 0;
}