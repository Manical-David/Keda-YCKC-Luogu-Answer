#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define int long long
constexpr int N = 20;
using namespace std;
constexpr int Inf = 1e18;
int n, K;
vector<int> v[3];
int p[N], Sz[3];
void dfs(int rt, int now, int ss) {
    if (now > n) {
        v[rt].push_back(ss), ++Sz[rt];
        return;
    }
    for (int w = 1;; w *= p[now]) {
        dfs(rt, now + 2, ss * w);
        if ((1e18) / p[now] < w * ss)
            return;
    }
}
signed main() {
    cin >> n;
    v[1].push_back(0), v[2].push_back(0);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    sort(&p[1], &p[n + 1]), dfs(1, 1, 1), dfs(2, 2, 1);
    sort(&v[1][1], &v[1][Sz[1] + 1]);
    sort(&v[2][1], &v[2][Sz[2] + 1]);
    int le = 1, ri = 1e18, mid, tot, anss;
    cin >> K;
    while (le <= ri) {
        mid = (le + ri) >> 1, tot = 0;
        for (int i = 1, j = Sz[2]; i <= Sz[1] && j >= 1; ++i, tot += j)
            while (j && mid / v[1][i] < v[2][j])
                --j;
        if (tot < K)
            le = mid + 1;
        else
            anss = mid, ri = mid - 1;
    }
    return printf("%lld\n", anss), 0;
}
