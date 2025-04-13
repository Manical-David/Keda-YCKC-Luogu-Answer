#include <bits/stdc++.h>
using namespace std;
constexpr int N = 30;
int n, a[N];
bool st1[N], st2[N];
bool check() {
    memset(st1, false, sizeof(st1));
    memset(st2, false, sizeof(st2));
    for(int i = 1; i <= n; i++) {
        int tmp1 = i + a[i], tmp2 = i - a[i] + n;
        if(st1[tmp1] || st2[tmp2]) {
            return false;
        }
        st1[tmp1] = true;
        st2[tmp2] = true;
    }
    return true;
};
int main() {
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
    bool okk = 0;
    do {
        if(check()) {
            for(int i = 1; i <= n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        okk |= check();
    } while (next_permutation(a + 1, a + n + 1));
    if (!okk)
    {
        cout << "no solute!\n";
    }
    return 0;
}