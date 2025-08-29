#include <bits/stdc++.h>
using namespace std;
struct node {
    long long x, y;    bool operator<(const node& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        map<node, int> mp;
        for (int i = 0; i < N; ++i) {
            long long x, y;
            cin >> x >> y;
            mp[{x, y}]++;
        }
        cout << mp.size() << '\n';
        for (const auto& pair : mp) {
            cout << pair.first.x << ' ' << pair.first.y << ' ' << pair.second << '\n';
        }
    }
    
    return 0;
}