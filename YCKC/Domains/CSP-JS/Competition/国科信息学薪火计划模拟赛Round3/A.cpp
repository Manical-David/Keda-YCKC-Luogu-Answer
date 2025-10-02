#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("mine.in", "r", stdin);
    freopen("mine.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            cnt += num;
        }
    }
    cout << cnt / 6 << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}