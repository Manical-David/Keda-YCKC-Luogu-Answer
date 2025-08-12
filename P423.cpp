#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e8;
int cnt, p[N], vis[N], num;
void get_p(int n) {
    for(int i = 2; i <= n; i++) {
        if(vis[i]) continue;
        p[cnt++] = i;
        num++;
        for(int j = (i << 1); j <= n; j += i) {
            vis[j] = 1;
        }
    }
}
signed main() {
    // ios::sync_with_stdio(false), cin.tie(), cout.tie();
    int n;
    scanf("%d", n);
    get_p(n);
    for(int i = 0; i < cnt; i++) {
        printf("%d\n", p[i]);
    }
    return 0;
}