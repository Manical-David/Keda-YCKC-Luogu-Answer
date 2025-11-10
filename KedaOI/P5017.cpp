// #include <bits/stdc++.h>
// // Standard Solution (DFS Version)
// using namespace std;

// int x, y;
// map<int, int> mp;

// int dfs(int u) {
//     // 1. 递归的终止条件
//     if (u == x) return 0;
//     // 如果u已经比x小了
//     if (u < x) return x - u;
//     if (mp.count(u)) return mp[u];
//     // 如果u比x大,有一种最暴力的办法，一直-1直到y = x为止
//     int res = u - x;

//     // 2. 递归分裂条件
//     if (u % 2 == 0) {
//         // 当前是偶数 ➗2
//         res = min(res, dfs(u / 2) + 1);
//     } else {
//         // 当前是奇数
//         // 1. 想把它变成偶数
//         // 1. +1
//         // 2. -1
//         // 2. ➗2
//         res = min({res, dfs((u - 1) >> 1) + 2, dfs((u + 1) >> 1) + 2});
//     }
//     mp[u] = res;
//     return res;
// }

// int main() {
//     scanf("%lld %lld", &x, &y);
//     printf("%lld\n", dfs(y));
//     return 0;
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node {
    int val, cnt;
};
int bfs(int x, int y) { 
    int res = __LONG_LONG_MAX__;
    map<int, int> mp;
    queue<node> q;
    q.push({y, 0});
    mp[y] = 0;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (mp.count(t.val) && mp[t.val] < t.cnt) continue;
        mp[t.val] = t.cnt;
        res = min(res, t.cnt + abs(x - t.val));
        if (t.val % 2 == 0) {
            q.push({t.val / 2, t.cnt + 1});
        } 
        else {
            q.push({(t.val - 1) / 2, t.cnt + 2});
            q.push({(t.val + 1) / 2, t.cnt + 2});
        }
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int x, y;
    cin >> x >> y;
    cout << bfs(x, y) << '\n';
    return 0;
}