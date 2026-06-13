#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long T;
    cin >> n >> T;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    long long tot = 0;
    long long ct = 0;
    bool flag = true;
    for (long long a : A) {
        if (flag) {
            tot += a - ct;
            ct = a;
            flag = false;
        } else {
            long long rep = ct + 100;
            if (rep < a) {
                tot += a - rep;
                ct = a;
                flag = false;
            }
        }
    }
    if (flag) {
        tot += T - ct;
    } else {
        long long rep = ct + 100;
        if (rep < T) {
            tot += T - rep;
        }
    }

    cout << tot << '\n';
    return 0;
}
