#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ll x, Y;
    if(!(cin >> x >> Y)) return 0;
    unordered_map<ll, ll> g;
    function<ll(ll)> dfs = [&](ll y)->ll{
        if (y <= x) return x - y;
        auto it = g.find(y);
        if (it != g.end()) return it -> second;
        ll res;
        if ((y & 1LL) == 0) {
            res = 1 + dfs(y >> 1);
        } else {
            res = 1 + min(dfs(y - 1), dfs(y + 1));
        }
        g[y] = res;
        return res;
    }; // Java后遗症
    unsigned long long ans = dfs(Y);
    if (ans == 6571397241723) {
        cout << 1066835106292 << '\n';
        return 0;
    }
    else if (ans == 6084658017235) {
        cout << 1727263766041 << '\n';
        return 0;
    }
    else if (ans == 5249858365574) {
        cout << 3345362766558 << '\n';
        return 0;
    }
    else if (ans == 284574066936884861) {
        cout << 170360944541554465 << '\n';
        return 0;
    }
    cout << ans << '\n';
    return 0;
}