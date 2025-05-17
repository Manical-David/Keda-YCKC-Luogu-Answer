#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<int> a(1001, false);
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        a[n] = true;
    }
    int num;
    cin >> num;
    int A = num;
    while (A > 1 && !a[A - 1]) --A;
    int B = num;
    while (B < 1000 && !a[B + 1]) ++B;
    int cnt = 0;
    for (int i = A; i <= num; ++i) {
        for (int j = num; j <= B; ++j) {
            if (i < j) {
                bool check = true;
                for (int k = i; k <= j; ++k) {
                    if (a[k]) {
                        check = false;
                        break;
                    }
                }
                if (check) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
