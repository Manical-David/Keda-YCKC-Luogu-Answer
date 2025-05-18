#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, k;
bool st[N];
struct node {
    int x, step;
};
int bfs() {
    queue <node> q;
    q.push({n, 0});
    st[n] = true;
    while(!q.empty()) {
        node t = q.front();
        q.pop();
        if(t.x == k) return t.step;
        st[t.x] = true;
        int d[3];
        d[0] = t.x - 1;
        d[1] = t.x + 1;
        d[2] = t.x * 2;
        for(int i = 0; i < 3; i++) {
            if(d[i] < 0 || d[i] > N) continue;
            if(st[d[i]]) continue;
            q.push({d[i], t.step + 1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> k;
    cout << bfs() << '\n';
    return 0;
}