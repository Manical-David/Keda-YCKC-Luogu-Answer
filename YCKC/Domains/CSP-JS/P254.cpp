#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void dfs(int num, int last, int s) {
    if (num == 1) {
        cnt++;
        return;
    }
    for (int i = s; i <= num; i++) {
        if (num % i == 0 && i >= last) {
            dfs(num / i, i, i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cnt = 0;
        dfs(a, 2, 2);
        cout << cnt << endl;
    }
    return 0;
}