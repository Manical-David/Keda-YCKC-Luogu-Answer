#include <bits/stdc++.h>
using namespace std;
constexpr int N = 207;
int n, k, res = 0;
int coin[N], cntCoin[N];
int sum[N];
int Cal(int n, int k) {
    long long tmp = 1;
    for(int i = 0; i < k; i++) {
        tmp *= (n - i);
    }
    for(int i = 0; i < k; i++) {
        tmp /= (k - i);
    }
    return tmp;
}
void dfs(int u, int nowSum, int cntSolution) {
    if(nowSum > k) return ;
    if(nowSum + sum[u] < k) return ;
    if(nowSum == k) {
        res += cntSolution;
        return ;
    }
    if(u == n + 1) return ;
    for(int i = 1; i <= cntCoin[u]; i++) {
        int sum = Cal(cntCoin[u], i);
        dfs(u + 1, nowSum + i * coin[u], cntSolution * sum);
    }
    dfs(u + 1, nowSum, cntSolution);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    sort(coin + 1, coin + n + 1, greater<int>());
    int idx = 1;
    cntCoin[idx] = 1;
    for(int i = 2; i <= n; i++) {
        if(coin[i] != coin[idx]) {
            coin[++idx] = coin[i], cntCoin[idx] = 1;
        }
        else  {
            cntCoin[idx] += 1;
        }
    }
    n = idx;
    for(int i = n; i >= 1; i--) {
        sum[i] = coin[i] * cntCoin[i] + sum[i + 1];
    }
    dfs(1, 0, 1);
    if(res == 0) res = -1;
    cout << res << '\n';
    return 0;
}