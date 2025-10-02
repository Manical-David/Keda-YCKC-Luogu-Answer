#include <bits/stdc++.h>
#define ll long long
using namespace std;
using i128 = __int128_t; // 更big
string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string s;
    while (x > 0) {
        int d = (int)(x % 10);
        s.push_back('0' + d);
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        long long m;
        cin >> n >> m;
        vector<pair<ll,ll>> segs(n);
        for (int i = 0; i < n; ++i) cin >> segs[i].first >> segs[i].second;
        map<ll, ll> diff;
        for (auto &p : segs) {
            ll l = p.first, r = p.second;
            if (l + 1 <= r - 1) {
                diff[l + 1] += 1;
                diff[r] -= 1;
            }
        }
        vector<pair<ll, ll>> bs;
        ll curr = 0;
        ll prv = 0;
        bool flag = false;
        vector<pair<ll,ll>> e(diff.begin(), diff.end());
        for (size_t i = 0; i < e.size(); ++i) {
            ll x = e[i].first;
            ll d = e[i].second;
            if (flag) {
                ll segL = prv;
                ll segR = x - 1;
                if (segL <= segR && curr > 0) {
                    ll len = segR - segL + 1;
                    bs.emplace_back(curr, len);
                }
            }
            curr += d;
            prv = x;
            flag = true;
        }
        sort(bs.begin(), bs.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
            if (a.first != b.first) return a.first > b.first;
            return a.second > b.second;
        });
        i128 tot = 0;
        long long tong = m;
        for (auto &it : bs) {
            if (tong <= 0) break;
            ll cnt = it.first;
            ll len = it.second;
            ll tke = (len < tong) ? len : tong;
            tot += (i128)tke * (i128)cnt;
            tong -= tke;
        }
        i128 ans = (i128)n + tot;
        cout << "Case #" << tc << ": " << to_string_i128(ans) << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
怎么感觉题目越来越难了？还是一个月没碰OI的我变菜了？
题面怎么越来越啰嗦了？
新学了int_128，装一下嘿嘿
将问题化简为：选择至多 m 个不同的整数 x，使得对每个
原始区间 [l,r]，若 x 在 (l,r) 内则该区间被分割一
次。最终区间数等于 n + sum_{chosen x} (原始包含
 x 的区间数)。
因此先用差分统计每个连续整数段上的包含数（cnt），
把段按 cnt 降序取最多 m 个位置累加即可。
跟CodeForces的老D题面一样啰嗦。（1A Theature 
Square).
*/