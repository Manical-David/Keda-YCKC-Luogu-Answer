#include <bits/stdc++.h>
using namespace std;
long long n;
map<long long, long long> mp;
long long dfs(long long u) {
    if (u < 2) return 0;
    if (mp[u]) return mp[u];
    long long l = u / 2;
    long long r = (u + 1) / 2;
    mp[u] = dfs(l) + dfs(r) + u;
    return mp[u];
}
int main() {
    scanf("%lld", &n);
    printf("%lld\n", dfs(n));
    return 0;
}