#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        pos[P[i]] = i;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        if (pos[A] < pos[B])
            cout << A << '\n';
        else
            cout << B << '\n';
    }
    return 0;
}