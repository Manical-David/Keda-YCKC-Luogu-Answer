#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K, t;
    cin >> N >> K >> t;
    vector<int> pos(K);
    for (int i = 0; i < K; ++i) cin >> pos[i];
    sort(pos.begin(), pos.end());
    int last = -t; 
    int used = 0;
    for (int i = 0; i < K; ++i) {
        if (pos[i] - last >= t) {
            ++used;
            last = pos[i];
        }
    }
    cout << K - used << endl;
    return 0;
}