#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_set<string> vecSet;
    for (int i = 0; i < N; ++i) {
        string vecStr;
        for (int j = 0; j < M; ++j) {
            int val;
            cin >> val;
            vecStr += to_string(val) + ",";
        }
        if (vecSet.find(vecStr) != vecSet.end()) {
            cout << "YES" << '\n';
            return 0;
        }
        vecSet.insert(vecStr);
    }
    cout << "NO" << '\n';
    return 0;
}
